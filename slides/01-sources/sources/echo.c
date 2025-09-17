/*
 * =====================================================================================
 *
 *       Filename:  echo.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 * 
 *   Description: Emula la comanda echo de Unix de forma molt bàsica
 *            Ús: ./echo <string>...
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <string>...\n", argv[0]);
        return EXIT_FAILURE;
    }
    while (*++argv) {
        printf("%s", *argv);
        if (argv[1]) printf(" ");
    }
    printf("\n");
    return EXIT_SUCCESS;
}
