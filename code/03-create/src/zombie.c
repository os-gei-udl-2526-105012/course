#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t pid;
    int i;
    for (i = 0; ; i++) {
        pid = fork();
        if (pid > 0) {
            printf("Zombie #%d born:\n",i + 1);
            sleep(1);
        } else {
            printf("*drool* Boooo!Arrgghh! *slobber*\n");
            exit(0);
        }
    }
    return 0;
}
