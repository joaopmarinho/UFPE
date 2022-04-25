#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// Definindo variáveis que serão utilizadas.
#define NUM_THREADS 4
#define CHUNK_SIZE 2
#define INICIO 0
#define PASSO 1
#define FINAL 15

typedef struct {
    int *partition;
    int num_partition;
} Divisions;

typedef struct {
    int inicio;
    int passo;
    int final;
    int thread_index;
    void (*f)(int);
} Args;

pthread_t THREADS[NUM_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int CHUNKS[1000];
Divisions partition = {CHUNKS, 0};

void printInteracoes(int i);
void *loop(void *args);
Divisions *schedule_static(int chunk_size, int num_threads, int iteracoes_restantes);
Divisions *schedule_dynamic(int chunk_size, int iteracoes_restantes);
Divisions *schedule_guided(int chunk_size, int num_threads, int iteracoes_restantes);
void omp_for( int inicio, int passo, int final, int schedule, int chunk_size, void (*f)(int));

int main() {
    // Perguntar ao usuário o tipo de escalonador
    int scheduleType;
    printf("Escolha o tipo de escalonador:\n1: Estatico\n2: Dinamico\n3: Guiado\n");
    scanf("%d", &scheduleType);
    void (*f)() = printInteracoes;
    omp_for(INICIO, PASSO, FINAL, scheduleType, CHUNK_SIZE, f);
}

void printInteracoes(int i) {
    printf("%d\n", i);
}

Divisions *schedule_static(int chunk_size, int num_threads, int iteracoes_restantes) {
    while (iteracoes_restantes > 0) {
        partition.num_partition++;

        if (chunk_size * num_threads < iteracoes_restantes)
            partition.partition[partition.num_partition - 1] = chunk_size;
        else {
            int retorno = iteracoes_restantes / num_threads; // Evitando erros
            if (retorno == 0) 
                retorno = iteracoes_restantes % num_threads;
            partition.partition[partition.num_partition - 1] = retorno;
        }
        // Evitando erros
        if (partition.partition[partition.num_partition - 1] == 0) partition.num_partition--;
        iteracoes_restantes -= partition.partition[partition.num_partition - 1];
    }
    return &partition;
}

Divisions *schedule_dynamic(int chunk_size, int iteracoes_restantes) {
    while (iteracoes_restantes > 0) {
        partition.num_partition++;

        if (iteracoes_restantes >= chunk_size) 
            partition.partition[partition.num_partition - 1] = chunk_size;
        else 
            partition.partition[partition.num_partition - 1] = iteracoes_restantes % chunk_size;
        // Evitando erros
        if (partition.partition[partition.num_partition - 1] == 0) partition.num_partition--;
        iteracoes_restantes -= partition.partition[partition.num_partition - 1];
    }
    return &partition;
}

Divisions *schedule_guided(int chunk_size, int num_threads, int iteracoes_restantes) {
    while (iteracoes_restantes > 0) {
        partition.num_partition++;
        
        if (ceil(iteracoes_restantes / num_threads) < chunk_size ) 
            partition.partition[partition.num_partition - 1] = chunk_size;
        else {
            float retorno = ceil((float)iteracoes_restantes / (float)num_threads);
            partition.partition[partition.num_partition - 1] = (int)retorno;
        }
        // Evitando erros
        if (partition.partition[partition.num_partition - 1] == 0) partition.num_partition--;
        iteracoes_restantes -= partition.partition[partition.num_partition - 1];
    }
    return &partition;
}

// For para ser a rotina das threads:
void *loop(void *args) {
    Args *props = (Args*) args;
    // Definindo variáveis:
    int inicio = props->inicio;
    int final = props->final;
    int index = props->thread_index;
    int passo = props->passo;
    // for padrão:
    if (inicio >= final) pthread_join(THREADS[index], NULL);
    (*props).f(inicio);
    props->inicio += passo;
    loop(args);
}

void omp_for(int inicio, int passo, int final, int schedule, int chunk_size, void (*f)(int)) {
    if (schedule == 1) {
        printf("Foi escolhido o escalonador estatico.\n");
        Divisions *chunks = schedule_static(chunk_size, NUM_THREADS, final);
        int copy_num_partition = chunks->num_partition;
        Args props[30] = {inicio, passo, final, 0, f};
        float ondas = ceil((float)copy_num_partition / (float)NUM_THREADS);
        int start = inicio;

        // Configurando as ondas:
        for (int thread = 0; thread < copy_num_partition; thread++){
            props[thread].thread_index = thread % NUM_THREADS;
            props[thread].final = props[thread].inicio + chunks->partition[thread];

            start = props[thread].final;
            if (thread != copy_num_partition) // Pegando o inicio da próxima:
                props[thread + 1].inicio = start;

            printf("N: %d - I: %d, F: %d\n", props[thread].thread_index, props[thread].inicio, props[thread].final);
        }
        for (int k = 0; k < copy_num_partition; k++) {
            pthread_create(&THREADS[k % NUM_THREADS], NULL, loop, &props[k]);
        }
    } else if (schedule == 2) {
        printf("Foi escolhido o escalonador dinamico.\n");
        Divisions *chunks = schedule_dynamic(chunk_size, final);
        int copy_num_partition = chunks->num_partition;
        Args props[30] = {inicio, passo, final, 0, f};
        float ondas = ceil((float)copy_num_partition / (float)NUM_THREADS);
        int start = inicio;

        for (int thread = 0; thread < copy_num_partition; thread++){
            props[thread].thread_index = thread % NUM_THREADS;
            props[thread].final = props[thread].inicio + chunks->partition[thread];

            start = props[thread].final;
            if (thread != copy_num_partition) // Pegando o inicio da próxima:
                props[thread + 1].inicio = start;
            printf("N: %d - I: %d, F: %d\n", props[thread].thread_index, props[thread].inicio, props[thread].final);
        }
        for (int k = 0; k < copy_num_partition; k++) {
            pthread_create(&THREADS[k % NUM_THREADS], NULL, loop, &props[k]);
        }

    } else if (schedule == 3) {
        printf("Foi escolhido o escalonador guiado.\n");
        Divisions *chunks = schedule_guided(chunk_size, NUM_THREADS, final);
        int copy_num_partition = (int) chunks->num_partition;
        Args props[30] = {inicio, passo, final, 0, f};
        float ondas = ceil((float)copy_num_partition / (float)NUM_THREADS);
        int start;

        for (int thread = 0; thread < copy_num_partition; thread++){
            props[thread].thread_index = thread % NUM_THREADS;
            props[thread].final = props[thread].inicio + chunks->partition[thread];

            start = props[thread].final;
            if (thread != copy_num_partition) // Pegando o inicio da próxima:
                props[thread + 1].inicio = start;
            printf("N: %d - I: %d, F: %d\n", props[thread].thread_index, props[thread].inicio, props[thread].final);
            
        }
        for (int k = 0; k < copy_num_partition; k++) {
            pthread_create(&THREADS[k % NUM_THREADS], NULL, loop, &props[k]);
        }
    } else {
        printf("Escalonador inválido\n");
        printf("Retornando ao main:\n");
        main();
    }
}