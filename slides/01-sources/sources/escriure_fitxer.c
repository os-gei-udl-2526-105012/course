/*
 * =====================================================================================
 *
 *       Filename:  escriure_fitxer.c
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 *   
 *    Description: Aquest programa mostra com escriure en un fitxer caràcters utilitzant
 *                 la crida al sistema write. Aquesta crida al sistema necessita com a
 *                 paràmetres el descriptor de fitxer, un punter a la cadena de caràcters
 *                 que es vol escriure i la longitud de la cadena.
 * 
 *                 La funció strlen() retorna la longitud de la cadena de caràcters.
 * 
 *                 En aquest exemple, s'escriu la cadena "Winter is coming" en un fitxer
 *                 anomenat got a la carpeta files.
 * 
 * =====================================================================================
 */
#include <string.h> // strlen() function
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int 
main() {

  const char* string = "\nWinter is coming\n\n";

  int file = open("files/got", O_CREAT|O_WRONLY, 0644);
  if(file == -1) {
    perror("Error en obrir el fitxer");
    exit(1);
  }

  write(file, string, strlen(string));
  close(file);

  exit(0);
}
