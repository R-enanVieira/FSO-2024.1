#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char path[256], cmd[256];

  struct timeval total_start, total_end;
  double total_time = 0.0;

  while (scanf("%s %s", path, cmd) != EOF) {
    struct timeval start, end;
    double time;
    gettimeofday(&start, NULL);

    pid_t pid = fork();

    if (!pid) {
      execl(path, path, cmd, (char*)NULL);
      printf("> Erro: %s\n", strerror(errno));
      fclose(stdin);
      return errno;
    } else {
      int s;
      waitpid(pid, &s, 0);

      gettimeofday(&end, NULL);
      time = (double)(end.tv_sec - start.tv_sec) +
             (double)(end.tv_usec - start.tv_usec) / 1000000;
      printf("> Demorou %.1lf segundos, retornou %d\n", time, WEXITSTATUS(s));
      fflush(stdout);
      total_time += time;
    }
  }

  printf(">> O tempo total foi de %.1lf segundos\n", total_time);

  return 0;
}
