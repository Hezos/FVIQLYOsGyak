#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd;
	int pipefd[2];
     pid_t cpid;
     char buf;
     char szoveg[32];
	buf[0]=0;
	char name[] = {'F','V','I','Q','L','Y'};
    switch (fork())
    {
    case 0:
      if (prctl(PR_SET_NAME, (unsigned long) name) < 0)
        perror("prctl()");
        cpid = 0;
      break;
    case -1:
      perror("fork()");
      break;
    default:
      if (wait(NULL) < 0)
        perror("wait()");
    }

    if(cpid == 0){
        szoveg = "Nagy Bence";
        write(pipefd[0], szoveg, strlen(szoveg));
    }else{
        if(cpid != NULL){
           while (read(pipefd[1], &buf, 1) > 0) {
		 printf("%c",buf);
            }
        }
    }

    return 0;
}
