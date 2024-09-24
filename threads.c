#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct thread_arg {
  int num;
};

void *thread_func(void *arg) {
  struct thread_arg *ctx = arg;

  printf("Hello, world %d\n", ctx->num);
  
  return NULL;
}

int main() {
  int ret, i;
  struct thread_arg args[NUM_THREADS];
  pthread_t threads[NUM_THREADS];

  for (i = 0; i < NUM_THREADS; i++) args[i].num = i;

  for (i = 0; i < NUM_THREADS; i++) {
    printf("Creating %d\n", i);
    ret = pthread_create(&threads[i], NULL, &thread_func, &args[i]);
    if (ret) {
      printf("Error %d on thread %d\n", ret, i);
      perror("pthread_create");
      exit(-1);
    }
  }
  
  for(i = 0; i < NUM_THREADS; i++) {
    ret = pthread_join(threads[i], NULL);
    if(ret){
      printf("Error %d on thread %d\n", ret, i);
      perror("pthread_create");
      exit(-1);
    }
  }

  pthread_exit(NULL);

  return 0;
}
