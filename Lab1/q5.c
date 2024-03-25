/* Disciplina: Computacao Concorrente */
/* Prof.: Silvana Rossetto */
/* Módulo 1 - Laboratório: 1 */
/* Codigo:  Programa que utiliza 8 threads retorna a² para todos os elementos de um array de 10000 elementos. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 8
#define ARRSIZE 100000000

typedef struct
{
    int *array, initPos, finalPos;
} t_Args;

void *power2(void *arg)
{
    t_Args *args = (t_Args *)arg;
    int i;
    for (i = args->initPos; i <= args->finalPos; i++)
    {
        args->array[i] = args->array[i] * args->array[i];
    }

    free(arg);

    pthread_exit(NULL);
}

int *createArr()
{
    int i, *array;

    array = calloc(ARRSIZE, sizeof(int));
    if (array == NULL)
    {
        printf("--ERROR: calloc\n");
        exit(-1);
    }

    for (i = 0; i < ARRSIZE; i++)
    {
        array[i] = i + 1;
    }

    return array;
}


void *verificaArr(int *array) {
    int i;
    long int verificador=1;

    for (i = 0; i < ARRSIZE; i++)
    {
        if(array[i] != (i + 1)*(i + 1)) {
            verificador = 0;
            printf("MATRIZ INCORRETA NA POSIÇÃO %d! \n", i+1);
            break;
        }
    }

    if(verificador == 1) {
        printf("MATRIZ CORRETA! \n");
    } 

    return (void *)verificador;
}

// funcao principal do programa
int main()
{
    pthread_t tid[NTHREADS];
    t_Args *args; // receberá os argumentos para a thread
    int primeiroValor = 0;
    int ultimoValor = ARRSIZE / NTHREADS;
    int *arr;

    arr = createArr();

    for (long int t = 0; t < NTHREADS; t++)
    {
        args = malloc(sizeof(t_Args));
        if (args == NULL)
        {
            printf("--ERRO: malloc()\n");
            exit(-1);
        }

        args->array = arr;
        args->initPos = primeiroValor;
        args->finalPos = ultimoValor;

        if (pthread_create(&tid[t], NULL, power2, (void *)args))
        {
            printf("--ERRO: pthread_create()\n");
            exit(-1);
        }

        primeiroValor = ultimoValor + 1;
        ultimoValor = ultimoValor + ARRSIZE / NTHREADS;
    }
    for (int t = 0; t < NTHREADS; t++){
        if (pthread_join(tid[t], NULL))
        {
            printf("--ERRO: pthread_join() \n");
            exit(-1);
        }
    }

    
    verificaArr(arr);
    printf("\n");
    pthread_exit(NULL);
}