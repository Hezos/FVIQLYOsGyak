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

	shmflg = 0;
	if ((shmid=shmget(key, size, shmflg)) < 0) {
	printf("Nincs meg szegmens! Keszitsuk el!\n");
	} else printf("Van mar ilyen shm szegmens!\n");
exit(0);
}
