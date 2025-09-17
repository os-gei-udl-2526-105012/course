/*
 * =====================================================================================
 *
 *       Filename:  arrel.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 *
 * =====================================================================================
 */
#include <math.h>
#include <stdio.h>

int
main (void)
{
  double x = 2.0;
  double y = sqrt (x);
  printf ("La rai­z cuadrada de %f es %f\n", x, y);
  return 0;
}

// gcc -Wall SO_usingLibraries.c /usr/lib/x86_64-linux-gnu/libm.a -o calc
// gcc -Wall SO_usingLibraries.c -lm -o calc

