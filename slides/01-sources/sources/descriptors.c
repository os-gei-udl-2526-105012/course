/*
 * =====================================================================================
 *
 *       Filename:  descriptors.c
 *
 *        Version:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Jordi Mateo
 *   Organization:  Universitat de Lleida
 * 
 *   Description: Aquest programa ens permet veure com es gestionen els descriptos 
 * 				  de fitxers. Cada vegada que obrim un fitxer, el sistema operatiu
 * 				  ens assigna un descripto de fitxer. Aquest descripto és un enter
 * 				  que identifica el fitxer dins del sistema operatiu.
 * 
 * 				  Primer observem com els descriptos de fiters estan associats a
 * 				  les tres primeres entrades de la taula de descriptos de fitxers
 * 				  (STDIN_FILENO, STDOUT_FILENO i STDERR_FILENO). Amb els enters 
 * 				  0, 1 i 2 respectivament. 
 * 
 * 				  Després obrim el fitxer /dev/zero tres vegades. En el primer cas
 * 				  obtenim el descriptor 3, en el segon cas el descriptor 4 i en el 
 * 				  tercer cas el descriptor 3 ja que el descriptor 3 estava lliure,
 * 				  pel tancament del fitxer obert en el primer cas.	
 *
 * =====================================================================================
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h> //fileno() 
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO

int
main() {
    int fd1, fd2, fd3;
    FILE *f;

    printf("STDIN_FILENO: %d\n", STDIN_FILENO);
    printf("stdin: %d\n", fileno(stdin));
    printf("STDOUT_FILENO: %d\n", STDOUT_FILENO);
    printf("stdout: %d\n", fileno(stdout));
    printf("STDERR_FILENO: %d\n", STDERR_FILENO);
    printf("stderr: %d\n", fileno(stderr));

    printf("\nObrint /dev/zero...\n");
    if ((fd1 = open("/dev/zero", O_RDONLY)) < 0) {
        fprintf(stderr, "No es pot obrir /dev/zero: %s\n", strerror(errno));
    } else {
        printf("fd1: %d\n", fd1);
    }

    printf("\nObrint /dev/zero una segona vegada...\n");
    if ((fd2 = open("/dev/zero", O_RDONLY)) < 0) {
        fprintf(stderr, "No es pot obrir /dev/zero: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("fd2: %d\n", fd2);

    printf("\nTancant fd1, però mantenint fd2 obert...\n");
    (void)close(fd1);

    printf("\nObrint /dev/zero una tercera vegada...\n");
    if ((fd3 = open("/dev/zero", O_RDONLY)) < 0) {
        fprintf(stderr, "No es pot obrir /dev/zero: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("fd3: %d\n", fd3);

    printf("\nAra tancant fd2 i fd3.\n");
    (void)close(fd2);
    (void)close(fd3);

    printf("Ara obrint /dev/zero com a flux.\n");
    if ((f = fopen("/dev/zero", "r")) == NULL) {
        fprintf(stderr, "No es pot obrir /dev/zero: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("f: %d\n", fileno(f));
    (void)fclose(f);

    return EXIT_SUCCESS;
}
