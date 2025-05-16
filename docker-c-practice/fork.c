#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    int pid; // identificador de processo

    pid = fork(); // replicação do processo

    if (pid < 0) { // fork funcionou?
        perror("Erro:"); // não, encerra este processo
        exit(-1);
    } else { // sim, fork funcionou
        if (pid > 0) {
            // sou o processo pai
            wait(0); // espero meu filho concluir
        } else {
            // sou o processo filho
            // carrega outro código binário para executar
            execve("/bin/date", argv, envp);
            perror("Erro:"); // execve não funcionou
        }
    }

    printf("Tchau!\n");
    exit(0);
}
