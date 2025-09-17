/*
 * =====================================================================================
 *
 *       Filename:  ex1.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 *
 * =====================================================================================
 */

#include <stdio.h>

// Definim constants amb el preprocessador
#define x 10
#define y 5

int main() {
    // Imprimim el resultat de l'operació suma entre x i y
    printf("El resultat de l'operació: %d + %d = %d\n", x, y, x + y);
    return 0;
}
