#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 41234L
#define PERM 00666

int main( ) {
    int N;
    scanf("%d",N);
    int[N] semafors;

    for(int i= 0; i< N; i++){
    if ((semafors[i] = semget(KEY, 1, 0)) < 0) {
		if ((id = semget(KEY, 1, PERM | IPC_CREAT)) < 0) {
		 	perror(" A szemafor nem nyitható meg. ");
			exit(-1);
		}
	}
	else    {
		perror(" Már létezik a szemafor. ");
		exit(0);
        }
    }
}
