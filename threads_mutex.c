#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define THREADS_LOOPS 1000*1000

static int cont = 0;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg) {
  int i;
  for( i = 0; i < THREADS_LOOPS; i++) {
    pthread_mutex_lock(&mutex);
    cont++;
    pthread_mutex_unlock(&mutex);
  }
  
  return NULL;
}

int main() {
  int ret, i;
  pthread_t threads[NUM_THREADS];


  for (i = 0; i < NUM_THREADS; i++) {
    printf("Creating %d\n", i);
    ret = pthread_create(&threads[i], NULL, &thread_func, NULL);
    if (ret) {
      printf("Error %d on thread %d\n", ret, i);
      perror("pthread_create");
      exit(-1);
    }
  }
   
  while(cont < NUM_THREADS *THREADS_LOOPS) {
    printf("count %d/%d\n", cont, NUM_THREADS*THREADS_LOOPS);
  }
  pthread_exit(NULL);

  return 0;
}

