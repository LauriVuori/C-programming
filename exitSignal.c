#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void exit_signal(int sig) {
    printf("CTRL-C exit");
    exit(1);
}

int main(){
  signal(SIGINT, exit_signal); 
  while(1); 
} 