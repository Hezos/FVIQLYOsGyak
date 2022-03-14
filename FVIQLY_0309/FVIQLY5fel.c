#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>

#include <unistd.h>

void pr_exit(int status);

int main()
{

pid_t pid;
int status2;
int *status;
pid = fork();
     if(pid >= 0){
        if(pid == 0){
            abort();
        }
    }
    if(WIFSIGNALED(status2)){
        printf("befejeződés sorszáma = %d\n", WTERMSIG(status2));
    }
    pr_exit(status2);
	return 0;
}
void pr_exit(int status){
    if(WIFEXITED(status)){
        printf("%d\n", WEXITSTATUS(status));
    }else if(WIFSIGNALED(status)){
        printf("%d\n", WTERMSIG(status));
    }
}