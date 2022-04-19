#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

// gyak ipc/pipe.c a név nélküli


int main()
{
    int pipefd[2];
    pid_t cpid;
    char buf;
    char szoveg[32];
    int ret;
    if(pipe(pipefd) == -1){
        printf("hiba a letrehozasnal");
        exit(-1);
    }
    cpid = fork();
    strcpy(szoveg,"Nagy Bence FVIQLY\0");
    if(cpid == 0){
        write(pipefd[1],szoveg,strlen(szoveg));
        close(pipefd[0]);
    }else{
        //szülõ processz
        close(pipefd(1));
        while(read(pipefd[0], &buf, 1) > 0){
            printf("%c", buf);
        }
        close(pipefd(1));
        exit(0);
    }


    return 0;
}
