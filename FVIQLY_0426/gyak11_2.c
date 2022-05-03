#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 41234L
#define PERM 00666

main( ) {
   sem_t my_semaphore;
    int value;
    pid_t pid;

	if ((value = semget(KEY, 1, 0)) < 0) {
		if ((id = semget(KEY, 1, PERM | IPC_CREAT)) < 0) {
		 	perror(" A szemafor nem nyitható meg. ");
			exit(-1);
		}
	}
	else    {
		perror(" Már létezik a szemafor. ");
		exit(0);
	}

	sem_init(&my_semaphore, 0, 10);
    sem_getvalue(&my_semaphore, &value);

    for(int i = 0; i< 3; i++){
        pid = fork();
        if(pid != 0){
        sleep(3);
            if ((value = semget(KEY, 1, 0)) < 0) {
                if ((id = semget(KEY, 1, PERM | IPC_CREAT)) < 0) {
                    perror(" A szemafor nem nyitható meg. ");
                    exit(-1);
            }else{
                printf("%d", value);
            }
        }
            else    {
                perror(" Már létezik a szemafor. ");
                exit(0);
            }
        }
    }

	//megszûntetés
	if (semctl(id, 0, IPC_RMID, 0) < 0) {
		perror(" Nem sikerült törölni.");
		exit(-1);
	}


	exit(0);
}

