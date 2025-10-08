---
title: "Creació i gestió de processos"
subtitle: "Unitat 3 · Sistemes Operatius (SO)"
author: "Jordi Mateo Fornés"
logo: "/figures/corporative/institute.png"
lang: "ca"

execute:
  freeze: auto
  echo: false
---

En aquests apunts veurem un exemple en `C` al **user space** de com es creen i gestionen processos amb `fork()`, com s'executen nous programes amb `exec()` i com es pot esperar que un procés fill acabi amb `wait()`.  
A més, aprendrem a **utilitzar senyals** per sincronitzar processos.. 

## Enunciat

Volem implementar un programa en `C` que permeti generar bitllets de loteria de forma concurrent.  
El programa principal (**pare**) ha de generar 5 processos fills que s'encarregaran de generar els números del bitllet.  

Cada procés fill:
- genera un número aleatori entre 0 i 9,  
- el retorna al pare com a **codi de sortida** (`exit(status)`).

El procés pare:
- espera tots els fills (`waitpid()`),  
- recull els números i construeix el **bitllet de loteria** (un nombre de 5 dígits).

```{mermaid}
 %%| echo: false

sequenceDiagram
    autonumber
    participant P as Pare
    participant F1 as Fill 1
    participant F2 as Fill 2
    participant F3 as Fill 3
    participant F4 as Fill 4
    participant F5 as Fill 5

    P->>F1: fork()
    P->>F2: fork()
    P->>F3: fork()
    P->>F4: fork()
    P->>F5: fork()

    F1-->>F1: genera num1
    F2-->>F2: genera num2
    F3-->>F3: genera num3
    F4-->>F4: genera num4
    F5-->>F5: genera num5

    F1-->>P: exit(num1)
    F2-->>P: exit(num2)
    F3-->>P: exit(num3)
    F4-->>P: exit(num4)
    F5-->>P: exit(num5)

    P->>P: waitpid() i recull num1, num2, num3, num4, num5
    P->>P: construir bitllet i mostrar
    P->>P: exit()
```
    

## Solució bàsica


```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define NUM_FILLS 5

int main() {
    pid_t pid;
    int i, status;
    int bitllet = 0;

    for (i = 0; i < NUM_FILLS; i++) {
        pid = fork();
        if (pid < 0) {
            perror("fork error");
            exit(1);
        } else if (pid == 0) {
            srand(time(NULL) ^ getpid());
            int num = rand() % 10;
            printf("Fill PID %d genera %d\n", getpid(), num);
            exit(num);
        }
    }

    for (i = 0; i < NUM_FILLS; i++) {
        pid_t child_pid = waitpid(-1, &status, 0);
        if (WIFEXITED(status)) {
            int num = WEXITSTATUS(status);
            printf("Pare recull fill PID %d amb %d\n", child_pid, num);
            bitllet = bitllet * 10 + num;
        }
    }

    printf("Bitllet final del pare: %05d\n", bitllet);
    return 0;
}
```

## Ús de `exec()`: separació de responsabilitats

Ara volem que cada fill executi un programa separat (**generador**) que genera el número aleatori. De forma que el procés fill només s'encarrega de crear un nou procés amb `exec()` i el programa **generador** s'encarrega de generar el número aleatori i finalitzar amb `exit(num)`.

El codi del programa **generador** seria:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    srand(time(NULL) ^ getpid()); 
    int num = rand() % 10; 
    exit(num);
}
```

El codi del procés main (pare) es modificaria per utilitzar `exec()`:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define NUM_FILLS 5

int main() {
    pid_t pid;
    int i, status;
    int bitllet = 0;

    for (i = 0; i < NUM_FILLS; i++) {
        pid = fork();
        if (pid < 0) {
            perror("fork error");
            exit(1);
        } else if (pid == 0) {
            execl("./generador", "generador", NULL);
            perror("execl error"); 
            exit(1);
        }
    }

    for (i = 0; i < NUM_FILLS; i++) {
        pid_t child_pid = waitpid(-1, &status, 0);
        if (WIFEXITED(status)) {
            int num = WEXITSTATUS(status);
            printf("Pare recull fill PID %d amb %d\n", child_pid, num);
            bitllet = bitllet * 10 + num;
        }
    }

    printf("Bitllet de loteria del pare: %05d\n", bitllet);
    return 0;
}
```

## Sincronització amb senyals

Ara volem que el fill no generi el número fins que el pare li doni permís.

- Quan un fill s’inicia, envia un senyal `SIGUSR2` al pare per indicar-li ja estic preparat per generar el número.
- El para, en rebre aquest senyal, envia un senyal `SIGUSR1` al fill per indicar-li que ja pot generar el número.
- El fill quan rep el senyal `SIGUSR1`, genera el número i finalitza amb `exit(num)`.

```{mermaid}
 %%| echo: false
 sequenceDiagram
    autonumber
    participant P as Pare
    participant F as Fill

    P->>F: fork()
    F->>P: SIGUSR2 · estic llest
    P->>F: SIGUSR1 · ja pots generar
    F->>F: Genera número
    F->>P: exit(num)
    P->>P: waitpid() recull resultat
```

El nou codi de **generador_senyal** seria:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void generate_number() {
    srand(time(NULL) ^ getpid());
    int num = rand() % 10;
    printf("Fill PID %d genera %d\n", getpid(), num);
    exit(num);
}

void handler(int sig) {
    if (sig == SIGUSR1) generate_number();
}

int main() {
    signal(SIGUSR1, handler);

    kill(getppid(), SIGUSR2);

    while (1) pause();
}
```

El codi del procés pare es modificaria per gestionar les senyals:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define NUM_FILLS 5

volatile sig_atomic_t ready_fills = 0;

void sigusr2_handler(int sig) {
    ready_fills++;
}

int main() {
    pid_t pid;
    int status;
    int bitllet = 0;

    signal(SIGUSR2, sigusr2_handler);

    pid_t fills[NUM_FILLS];

    for (int i = 0; i < NUM_FILLS; i++) {
        pid = fork();
        if (pid < 0) {
            perror("fork error");
            exit(1);
        } else if (pid == 0) {
            execl("./generador_senyal", "generador_senyal", NULL);
            perror("execl error");
            exit(1);
        } else {
            fills[i] = pid;
            while (ready_fills <= i) pause();  // Espera que el fill estigui llest
            kill(pid, SIGUSR1);                // Envia permís al fill
        }
    }

    for (int i = 0; i < NUM_FILLS; i++) {
        pid_t child_pid = waitpid(fills[i], &status, 0);
        if (WIFEXITED(status)) {
            int num = WEXITSTATUS(status);
            printf("Pare recull fill PID %d amb %d\n", child_pid, num);
            bitllet = bitllet * 10 + num;
        }
    }

    printf("Bitllet de loteria final: %05d\n", bitllet);
    return 0;
}
```

