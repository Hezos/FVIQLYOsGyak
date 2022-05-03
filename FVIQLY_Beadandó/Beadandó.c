#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int glob=0;


void sigkiszolgalo(int valami) {
    glob=1;
}
int main() {  
   	signal(SIGUSR1, sigkiszolgalo);
     	
	 int pipefd[2];	
     pid_t cpid;	
     char buf;		
     char szoveg[32];	
     int ret;

     if (pipe(pipefd) == -1) {	
	   perror("pipe");
	   exit(-1);
     }

     cpid = fork();
     if (cpid == -1) {
	   perror("fork");
	   exit(-1);
     }

     if (cpid == 0) {  
       // Nem szülő 
	   
	   close(pipefd[0]);
	   strcpy(szoveg,"Let me throght pretty please!\0");
	   write(pipefd[1], szoveg, strlen(szoveg));
	   close(pipefd[1]);    /* EOF  */
	   
	   
   	   exit(0);	// kilep

     } else {	
	   close(pipefd[1]);
	   while (read(pipefd[0], &buf, 1) > 0) {
		 printf("%c",buf);
	   }
	   close(pipefd[0]);
	   
	   raise( SIGUSR1);
	   
	   // megvárjuk a gyerek processzt 
	   wait(NULL);    
	   exit(0);
     }
}