/*
 * =====================================================================================
 *
 *       Filename:  punters.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 * 
 *    Description:  En aquest programa es mostren les adreces de memòria i el contingut
 *                  de les variables s, n, m, ptr. Es un exemple il·lustratiu de com
 *                  funcionen els punters i les seces operacions.
 * 
 *                  Un punter és una variable que conté l'adreça de memòria d'una altra
 *                  variable. Una variable sempre té una adreça de memòria associada.
 * 
 *                  Per accedir a l'adreça de memòria d'una variable, utilitzem l'operador
 *                  &. Per accedir al contingut d'una adreça de memòria, utilitzem 
 *                  l'operador *.
 * 
 *                  Notes: 
 *                  (1) Utilitzem (void*) per a fer un cast de la variable ptr a un punter
 *                      a void. Això és necessari per a que la funció write() pugui interpretar
 *                      l'adreça de memòria com un punter.
 * 
 * =====================================================================================
 */
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char msg[250];
    int s = 10, n, m;
    int *ptr = &s;

    sprintf(msg, "La variable 's' és un enter i conté el valor %d.\n", s);
    write(STDOUT_FILENO, msg, strlen(msg));

    sprintf(msg, "La variable 'ptr' conté l'adreça on tenim guardat el valor de 's' = %p.\n", (void*)ptr);
    write(STDOUT_FILENO, msg, strlen(msg));

    sprintf(msg, "La variable '*ptr' conté el valor de 's' = %i.\n", *ptr);
    write(STDOUT_FILENO, msg, strlen(msg));

    sprintf(msg, "L'adreça de la variable 's' és %p.\n", (void*)&s);
    write(STDOUT_FILENO, msg, strlen(msg));

    sprintf(msg, "L'adreça de la variable 'n' és %p.\n", (void*)&n);
    write(STDOUT_FILENO, msg, strlen(msg));

    sprintf(msg, "L'adreça de la variable 'm' és %p.\n", (void*)&m);
    write(STDOUT_FILENO, msg, strlen(msg));

    sprintf(msg, "L'adreça de la variable 'ptr' és %p.\n", (void*)&ptr);
    write(STDOUT_FILENO, msg, strlen(msg));

    exit(EXIT_SUCCESS);
}
