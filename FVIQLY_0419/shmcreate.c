#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PKEY 431KEY

int main()
{
	int shmid;
	key_t key;
	int size=512;
	int shmflg;

	key = PKEY;
	   shmflg = 00666 | IPC_CREAT;
	   if ((shmid=shmget(key, size, shmflg)) < 0) {
	      perror("Az shmget() system-call sikertelen!\n");
	      exit(-1);
	   }
	printf("\nAz shm szegmens azonositoja %d: \n", shmid);

	exit(0);
}
