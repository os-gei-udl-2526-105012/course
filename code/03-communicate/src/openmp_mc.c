#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 2

int main(void) {
    int counter = 0;

    #pragma omp parallel num_threads(NUM_THREADS)
    {
        #pragma omp for
        for (int i = 0; i < 10000; i++) {
            #pragma omp atomic
            counter++;
        }
    }

    printf("Valor final del comptador: %d\n", counter);

    return 0;
}

