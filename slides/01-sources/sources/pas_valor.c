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
int sumar_per_valor(int a, int b);


int 
main() {

    int x = 5;
    int y = 3;

    printf("Abans de la crida per valor: x = %d, y = %d\n", x, y);

    int resultat = sumar_per_valor(x, y);
    
    printf("Després de la crida per valor: x = %d, y = %d\n", x, y);
    
    printf("Resultat de la suma: %d\n", resultat);
    
    return 0;
}

/*
 * Funció que suma dos enters i retorna el resultat
    * Paràmetres:
    *  a: enter
    *  b: enter
    * Retorna:
    *  enter
 */
int sumar_per_valor(int a, int b) {
    a = a + b;
    return a;
}

