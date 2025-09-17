/*
 * =====================================================================================
 *
 *       Filename:  escriure_fitxer2.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 * 
 *    Description:  En aquest exemple es mostra com podem llegir/esciure en un fitxer a
 *                  partir d'una posició determinada. Per això utilitzem la crida a sistema
 *                  lseek(). Aquesta crida ens permet moure la posició del descriptor 
 *                  de fitxer a una posició determinada.
 * 
 *                  En aquest exemple, escrivim buf1 al fitxer new_file2, després ens 
 *                  desplacem 4 bytes de l'inici i escrivim buf2.
 *
 * =====================================================================================
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main() {
  int fd;

  if((fd = creat("files/new_file2", 0644)) < 0) {
        perror("new_file2"); exit(-1);
  }

  if(write(fd, buf1, 10) != 10)       perror("buf1");    // offset == 10
  if(lseek(fd, 4, SEEK_SET) == -1)    perror("lseek");   // offset == 4
  if(write(fd, buf2, 10) != 10)       perror("buf2");    // offset == 14

  return 0;
}