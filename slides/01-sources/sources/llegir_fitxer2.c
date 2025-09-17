/*
 * =====================================================================================
 *
 *       Filename:  llegir_fitxer2.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 *
 *    Description:  En aquest exemple es mostra com llegir un fitxer a partir d'una
 *                  posició determinada. Per això, s'utilitza la crida a sistema 
 *                  lseek(). Aquesta crida permet moure la posició del punter de
 *                  lectura d'un fitxer a una posició determinada. En aquest cas,
 *                  es mou fins a la posició 46 del fitxer.
 * 
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
    perror("Error while opening file");
    exit(1);
  }

  lseek(file, 46, SEEK_SET);
  b_read = read(file, string, 10); // Read 10 bytes
  close(file);

  string[10] = 0;
  printf("%d B have been read. The obtained string is: %s\n", 
  b_read, string);

  return 0;
}