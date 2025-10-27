#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main(void) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char *message = "Aquest és un missatge de prova.";

    // Crear el socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("error en el socket");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convertir adreça IP de text a binari
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Adreça no vàlida o família d'adreces no suportada\n");
        return -1;
    }

    // Establir connexió amb el servidor
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connexió fallida");
        return -1;
    }

    // Enviar missatge al servidor
    send(sock, message, strlen(message), 0);
    printf("Missatge enviat al servidor.\n");

    char buffer[1024] = {0};

    // Llegir la resposta del servidor
    read(sock, buffer, 1024);
    printf("Resposta del servidor: %s\n", buffer);

    return 0;
}

