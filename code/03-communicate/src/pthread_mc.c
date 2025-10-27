#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

typedef struct {
    int counter;
} SharedData;

SharedData *sharedData;

void *incrementCounter(void *arg);
void *incrementCounter(void *arg) {
    for (int i = 0; i < 10000; i++) {
        sharedData->counter++;
    }
    pthread_exit(NULL);
}

int main(void) {
    pthread_t threads[NUM_THREADS];

    // Inicialitzem l'estructura de dades compartida
    sharedData = (SharedData *)malloc(sizeof(SharedData));
    sharedData->counter = 0;

    // Creem els fils d'execució
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, incrementCounter, NULL);
    }

    // Esperem que tots els fils d'execució finalitzin
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Valor final del comptador: %d\n", sharedData->counter);

    // Alliberem la memòria de l'estructura de dades compartida
    free(sharedData);

    return 0;
}

