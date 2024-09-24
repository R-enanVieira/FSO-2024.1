#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int cont;
pid_t p_son;

void sig_handler() {
 if(cont == 0) { 
  pid_t p = fork();
   
  if(p == 0) /*printf("%d: EU SOU O PROCESSO FILHO\n", getpid()),*/ p_son = getpid(), exit(0); 
 } else if (cont == 1){
  wait(&p_son);
  //printf("%d: TRATEI O RETORNO DO MEU FILHO QUE ERA ZUMBI\n", getpid());
 } else {
  exit(EXIT_SUCCESS);
 }
 cont++;
}

int main() { 
    //printf("%d\n", getpid());
    struct sigaction sa = {};
    sa.sa_handler = &sig_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1);
    
}

