// thread "main" (vai criar as demais threads)
// Exemplo de uso de threads Posix em C no Linux
// Compilar com: gcc exemplo.c -o exemplo -lpthread

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

// cada thread vai executar esta função
void *print_hello(void *threadid) {
    printf("%ld: Hello World!\n", (long) threadid);
    sleep(5);
    printf("%ld: Bye bye World!\n", (long) threadid);
    pthread_exit(NULL); // encerra esta thread
}



int main(int argc, char *argv[]) {
    pthread_t thread[NUM_THREADS];
    long status, i;

    // cria as demais threads
    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %ld\n", i);
        status = pthread_create(&thread[i], NULL, print_hello, (void *) i);

        if (status) { // ocorreu um erro
            perror("pthread_create");
            exit(-1);
        }
    }

    // encerra a thread "main"
    pthread_exit(NULL);
}
