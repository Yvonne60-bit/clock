/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
float hour=0.0;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  //exit(1); //exit after printing
  printf("turning was right\n");
  alarm(1); 
    
}
clock_t Initial;
void Measure (int signum)
{ clock_t time=clock();
  hour=(time-Initial)/CLOCKS_PER_SEC;
  printf("%f",hour);
  printf(" second");
  exit(1);
    
}

int main(int argc, char * argv[])
  
{ int chain;
  Initial=clock();
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  signal(SIGINT,Measure);
  while(1); //busy wait for signal to be delivered
  return 0; //never reached
}
