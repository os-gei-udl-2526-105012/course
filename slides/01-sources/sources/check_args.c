/*
 * =====================================================================================
 *
 *       Filename:  check_args.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 * 
 *   Description: Emula la comanda echo de Unix de forma molt bàsica
 *            Ús: ./check_args <string>...
 *
 * =====================================================================================
 */

#include <stdio.h>

int
main(int argc, char **argv) {
	int i;

	for (i=1; i<argc; i++) {
		printf("%s ", argv[i]);
	}
	printf("\n");
	return 0;
}
