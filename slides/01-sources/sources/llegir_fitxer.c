/*
 * =====================================================================================
 *
 *       Filename:  llegir_fitxer.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 *
 *    Description:  En aquest exemple es mostra com llegir un fitxer de forma bàsica
 *                  amb la crida a sistema read(). Aquesta crida llegeix un nombre
 *                  determinat de bytes d'un fitxer i els guarda en un buffer.
 *                  La crida a sistema retorna el nombre de bytes llegits.
 * 
 *                  Nota: El '0' indica el final de la cadena en C. Es important
 *                  assegurar-se que el buffer tingui un espai suficient per aquest
 *                  caràcter. Sense aquest caràcter, printf() no sabria on acabar de
 *                  llegir la cadena.
 * =====================================================================================
 */
#include <fcntl.h>  // Open modes
#include <unistd.h> // Many POSIX functions
#include <stdlib.h> // File functions
#include <stdio.h>  // Standard I/O

int main() {
  char string[11];
  int b_read;

  int file = open ("files/my_file", O_RDONLY); 
  if(file == -1) {
    perror("Error en obrir el fitxer");
    exit(1);
  }

  b_read = read(file, string, 10); 
  close(file);

  string[10] = 0; 
  printf("%d bytes s'han llegit. La cadena obtinguda és: %s\n", b_read, string);

  return 0;
}