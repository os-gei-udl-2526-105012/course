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
 * =====================================================================================
 */

#include <stdio.h>

// Capçaleres
void sumar_per_referencia(int *a, int *b);


int 
main() {

    int x = 5;
    int y = 3;

    printf("Abans de la crida per referència: x = %d, y = %d\n", x, y);

    sumar_per_referencia(&x, &y);

    printf("Després de la crida per referència: x = %d, y = %d\n", x, y);
    
    return 0;
}

/*
 * Funció que suma dos enters i retorna el resultat
    * Paràmetres:
    *  a: Apuntador a enter (Adreça de memòria per guardar un enter)
    *  b: Apuntador a enter (Adreça de memòria per guardar un enter)
    * Retorna:
    *  Aquesta funció no retorna res, però modifica el valor de a. El
    *  resultat de la suma es guarda a la posició de memòria apuntada per a.
    *  
 */
void sumar_per_referencia(int *a, int *b) {
    *a = *a + *b;
}

