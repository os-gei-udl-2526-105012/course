#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1) {
        perror("Error al crear el pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Error al fer fork");
        return 1;
    }

    if (pid == 0) { // Fil fill (lector)
        close(pipe_fd[1]);  // Tanquem l'extrem d'escriptura ja que no el farem servir
        char buffer[100];
        ssize_t bytes_llegits = read(pipe_fd[0], buffer, sizeof(buffer));
        close(pipe_fd[0]);  // Tanquem l'extrem de lectura després de llegir
        if (bytes_llegits > 0) {
            buffer[bytes_llegits] = '\0';  // Assegurem que el buffer acaba amb null-terminator
            printf("Missatge rebut pel fil fill: %s\n", buffer);
        } else {
            printf("No s'ha rebut cap missatge.\n");
        }
    } else { // Processa pare (escriptor)
        close(pipe_fd[0]);  // Tanquem l'extrem de lectura ja que no el farem servir
        char missatge[] = "Missatge des de Process pare";
        write(pipe_fd[1], missatge, strlen(missatge));
        close(pipe_fd[1]);  // Tanquem l'extrem d'escriptura després d'escriure
        wait(NULL);  // Esperem que el fil fill acabi
    }

    return 0;
}

