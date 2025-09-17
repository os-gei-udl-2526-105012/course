/*
 * =====================================================================================
 *
 *       Filename:  cd.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 * 
 *   Description: Emula la comanda cd de Unix de forma molt bàsica
 *            Ús: ./cd <directory>
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // chdir

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    if (chdir(argv[1]) == -1) {
        perror("chdir");
        return 1;
    }

    return 0;
}
