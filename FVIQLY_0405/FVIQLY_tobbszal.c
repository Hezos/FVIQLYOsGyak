#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void handleSignals(int signum){
  printf("\nInside handler function\n");
}

void kezelo(int i){
    printf("Signal kezelese: %d\n", i);
    return;
}

int main(){
 int sigIntCount = 0;
  if(signal(SIGINT,handleSignals) == 1){
        if(sigIntCount < 1){
             sigIntCount++;
        }else{
            raise(SIG_DFL);
            exit(0);
        }
  }
  signal(SIGQUIT,handleSignals);
  printf("Signal kezelo atvetele: %d\n", signal(SIGQUIT, &kezelo);
  for(int i=1;;i++){
    printf("%d : Inside main function\n",i);
    sleep(1);
  }
  return 0;
}

