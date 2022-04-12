#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/ipc.h>

int f(int sigterm);

int main(*argv)
{
    pid = atoi(argv[1]);
    while(1){
        f(SIGTERM(pid));
        sleep(3)
    }

	exit(0);
}
int f(int sigterm){
    return SIGTERM;
}

