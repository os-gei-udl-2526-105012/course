#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
    int fd;
    char *fifoPath = "/tmp/my_fifo"; // Path del FIFO
    char message[100];

    // Obrim el FIFO en mode lectura
    fd = open(fifoPath, O_RDONLY);

    // Llegim el missatge del FIFO
    read(fd, message, 100);
    printf("Missatge rebut: %s\n", message);

    close(fd); // Tanquem el FIFO

    // Eliminem el FIFO
    unlink(fifoPath);

    return 0;
}

