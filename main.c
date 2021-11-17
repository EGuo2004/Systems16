#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
  printf("Forking\n");
  int fork1 = fork();

  if(fork1) {
    printf("Forking\n");
    int fork2 = fork();
    if(fork2) {
      int status;
      wait(&status);
      int temp = WEXITSTATUS(status);
      printf("%d finished sleeping after %d seconds\n", status, temp);
      printf("Parent finished\n");
      exit(0);
    } else {
      printf("Second Child pid: %d\n", getpid());
      srand(time(NULL));
      int time = (rand() % 4) + 2;
      sleep(time);
      printf("Second Child has finished sleeping\n");
      return time;
    }
  } else {
    printf("First Child pid: %d\n", getpid());
    srand(time(NULL));
    int time = (rand() % 4) + 2;
    sleep(time);
    printf("First Child has finished sleeping\n");
    return time;
  }
}
