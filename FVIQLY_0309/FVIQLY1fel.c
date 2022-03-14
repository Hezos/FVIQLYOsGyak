#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#include <unistd.h>

int main()
{
  int status;
    if((status = system("date")) < 0){
        perror("system() error");
    }
    if(WIFEXITED(status)){
        printf("Normális befejeződés, visszaadott érték = %d\n", 		WEXITSTATUS(status));
    }
//hibás
    if((status = system("FVIQLY")) < 0){
        perror("system() error");
    }
	return 0;
}