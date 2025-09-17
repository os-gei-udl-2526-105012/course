/*
 * =====================================================================================
 *
 *       Filename:  SO_errno_example.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 * 
 *   Description:  Exemple de com gestionar errors amb errno
 *                 Intentem obrir un fitxer que no existeix
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>

extern errno;

int main () {

   FILE * pf;
   int errnum;
   pf = fopen ("no_existeix.txt", "rb");
	
   if (pf == NULL) {
      errnum = errno;
      // Nota: Això no és una bona pràctica, tenim debuggers per això
      fprintf(stderr, "Valor de la variable (errno): %d\n", errno);
      perror("Error imprimit per perror");
      fprintf(stderr, "Error obrint el fitxer: %s\n", strerror( errnum ));
   }
   else {
      fclose (pf);
   }
   
   return 0;
}
