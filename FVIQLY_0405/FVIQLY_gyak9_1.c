#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGKEY 654321L


int main(*argv)
{
pid_t pid;
	pid = atoi(argv[1]);
	if(kill(pid, SIGALRM) == 1) {
		printf(" \n FVIQLY \n");
		pause();
		exit(1);
	}

	exit(0);
}

