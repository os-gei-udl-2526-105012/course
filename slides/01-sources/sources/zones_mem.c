/*
 * =====================================================================================
 *
 *       Filename:  zones_mem.c
 *        
 *        Version:  1.0
 *       Compiler:  gcc
 *      
 *    Description:  En aquest programa es mostra com es distribueix la memòria en un procés
 *                  de Linux. Es mostren les diferents zones de memòria (heap, stack)
 *                  i com es pot accedir a la informació de la memòria del procés 
 *                  a través del sistema de fitxers /proc/self/maps.
 * 
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 * 
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int y;                 // Variable local (Stack)        
    char *str;             // Punter a caràcter (Heap)
    FILE *maps;           // Punter a fitxer


    printf("\nInformació de la memòria del procés:\n");
    maps = fopen("/proc/self/maps", "r");
    if (maps == NULL) {
        perror("Error en obrir /proc/self/maps");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), maps)) {
        if (strstr(line, "[heap]") != NULL) {
            printf("Regió (heap): %s", line);
        }
        if (strstr(line, "[stack]") != NULL) {
            printf("Regió (stack): %s", line);
        }
    }

    fclose(maps);

    y = 4;
    printf("[Stack] - adreça de 'y': %p, valor: %d\n", (void*)&y, y);

    str = malloc(100 * sizeof(char)); 
    if (str == NULL) {
        perror("Error en reservar memòria");
        exit(EXIT_FAILURE);
    }
    
    str[0] = 'm';  
    printf("[Heap] - adreça de 'str': %p, valor: %c\n", (void*)str, str[0]);

    free(str);         

    return 0;
}
