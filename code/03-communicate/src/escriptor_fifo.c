#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    int fd;
    char *fifoPath = "/tmp/my_fifo"; // Path del FIFO

    // Creem el FIFO (si no existeix)
    mkfifo(fifoPath, 0666);

    char message[] = "Hola, aquest és un missatge des de l'escriptor.";
    fd = open(fifoPath, O_WRONLY); // Obrim el FIFO en mode escriptura

    write(fd, message, strlen(message) + 1); // Escrivim el missatge al FIFO
    close(fd); // Tanquem el FIFO

    return 0;
}

