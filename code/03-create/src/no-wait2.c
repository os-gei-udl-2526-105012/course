#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("%s\n", "I am the child.");
    } else {
        printf("%s\n", "I am the parent.");
    }

    // No s'espera al fill, permetent que aquest imprimeixi abans que el pare en algunes execucions

    return EXIT_SUCCESS;
}