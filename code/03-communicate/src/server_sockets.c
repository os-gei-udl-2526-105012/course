#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main(void) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *response = "Missatge rebut pel servidor.";

    // Crear el socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("error en el socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Assignar adreça al socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("error en bind");
        exit(EXIT_FAILURE);
    }

    // Escoltar les connexions
    if (listen(server_fd, 3) < 0) {
        perror("error en listen");
        exit(EXIT_FAILURE);
    }

    printf("Servidor escoltant en el port %d\n", PORT);

    // Acceptar una nova connexió
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("error en accept");
        exit(EXIT_FAILURE);
    }

    // Llegir el missatge rebut del client
    read(new_socket, buffer, 1024);
    printf("Missatge rebut del client: %s\n", buffer);

    // Enviar una resposta al client
    send(new_socket, response, strlen(response), 0);
    printf("Resposta enviada al client.\n");

    return 0;
}

