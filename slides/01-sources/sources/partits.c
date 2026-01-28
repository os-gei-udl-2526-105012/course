#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIDA 3

typedef struct
{
    int golsFavor; 
    int golsContra;
} partit;

int generar_valor();
int checkParells(int* suma, partit** partits);

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Ús : %s <string>\n", argv[0]);
        return 1;
    }

    srand(time(NULL));
    partit** partits = malloc(MIDA * sizeof(partit *));

    for(int i = 0; i < MIDA; i++)
    {
        partits[i] = malloc(MIDA * sizeof(partit));
    }

    for (int i = 0; i < MIDA; i++) 
    {
        for(int j = 0; j < MIDA; j++)
        {
            partits[i][j].golsFavor = generar_valor();
            partits[i][j].golsContra =  generar_valor();
        }
    }
    for (int i = 0; i < MIDA; i++) 
    {
        for(int j = 0; j < MIDA; j++)
        {
            printf("%d %d ", partits[i][j].golsFavor,partits[i][j].golsContra);
        }
        printf("\n");
    }
    int suma = atoi(argv[1]);
    int count = checkParells(&suma, partits);
    printf("El total de partits amb suma %d son: %d \n",suma, count);

    for(int i = 0; i < MIDA; i++)
    {
        free(partits[i]);
    }
    free(partits);
    return 0;
}

int generar_valor() {
    double r = (double) rand() / RAND_MAX;
    //No podem utilitzar switch. Digueu el perqué.
    if (r < 0.25) return 0;
    else if (r < 0.5) return 1;
    else if (r < 0.7) return 2;
    else if (r < 0.85) return 3;
    else if (r < 0.93) return 4;
    else if (r < 0.975) return 5;
    else return 6;
}

int checkParells(int* suma, partit** partits)
{
    int count = 0;
    for(int i = 0; i < MIDA; i++)
    {
        for(int j = 0; j < MIDA; j++)
        {
            if((partits[i][j].golsFavor + partits[i][j].golsContra) == *suma)
            {
                count++;
            }
        }
    }
    return count;
}