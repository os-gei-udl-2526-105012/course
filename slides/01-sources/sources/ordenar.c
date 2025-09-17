/*
 * =====================================================================================
 *
 *       Filename:  pas_valor.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 *
 *    Description: Aquest programa ordena un array d'enters utilitzant l'algorisme de
 *                 bombolla. Els elements de l'array són introduïts per l'usuari utilitzant
 *                 l'entrada estàndard. 
 * 
 *                 La finalitat d'aquest programa és il·lustrar com funciona la memòria
 *                 dinàmica en C, així com l'ús de punters i la passada de paràmetres.
 * =====================================================================================
 */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Funció que ordena un array d'enters utilitzant l'algorisme de bombolla.
 * 
 * @param n Nombre d'elements de l'array.
 * @param ptr Punter a l'array d'enters que es vol ordenar. Aquest paràmetre és un
 *            paràmetre d'entrada/sortida.
 */
void ordenar(int n, int* ptr)
{
    int i, j, t;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (*(ptr + j) < *(ptr + i)) {
                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }
}

int 
main() {
    char msg[250];
    int *a, n, i;

    sprintf(msg, "Introdueix el nombre d'elements de l'array: \n");
    write(STDOUT_FILENO, msg, strlen(msg));
    scanf("%d", &n);

    a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        perror("Error en reservar memòria");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        sprintf(msg, "Introdueix un element de l'array: \n");
        write(STDOUT_FILENO, msg, strlen(msg));
        scanf("%d", a + i);
    }

    ordenar(n, a);


    for (i = 0; i < n; i++) {
        sprintf(msg, "a[%d] = %d\n", i, *(a + i));
        write(STDOUT_FILENO, msg, strlen(msg));
    }

    free(a);

    exit(EXIT_SUCCESS);
}
