#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void filhonaomorrera(int s) { printf("NAO MORREREI! DEIXE-ME EM PAZ\n"); }

int main() {
  pid_t x;
  x = fork();
  sleep(5);
  if (x == 0) {
    signal(SIGTERM, filhonaomorrera);
    printf("Sou filho, pid=%d e pai=%d\n", getpid(), getppid());
    while (1) {
      printf("HEHEHE");
      sleep(1);
    }
    return 3;
  }
}
