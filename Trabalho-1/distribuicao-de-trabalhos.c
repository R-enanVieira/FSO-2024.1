#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count;
pthread_mutex_t mut;

struct thread_arg {
  int vezes;
};

void work(int i) {printf("%d\n", i);}

void *thread_func(void *arg) {
 struct thread_arg *t_arg = (struct thread_arg *) arg;

 for(int i = 0; i < t_arg->vezes; i++) {
   pthread_mutex_lock(&mut);
   int id = count++;
   pthread_mutex_unlock(&mut);
   work(id);
 }
 return NULL;
}

int main() {
  int threads_num = 5;
  int work_per_thread = 2;
  pthread_t threads[threads_num];
  struct thread_arg args[threads_num];

  for(int i = 0; i < threads_num; i++) {
    args[i].vezes = work_per_thread;
    if(pthread_create(&threads[i], NULL, thread_func, &args[i]) != 0) {
      perror("Erro ao criar thread");
      exit(EXIT_FAILURE);
    }
  }

  for(int i = 0; i < threads_num; i++) {
    if(pthread_join(threads[i], NULL) != 0) {
      perror("Erro ao aguardar thread");
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}
