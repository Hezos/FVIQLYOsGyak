#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 431KEY

struct testStruct {
		int  hossz;
		char szoveg[512-sizeof(int)];
	} *segm;

int main()
{
	int shmid;
	key_t key;
	int size=512;
	int shmflg;

	key = SHMKEY;

	shmflg = 0;
	if ((shmid=shmget(key, size, shmflg)) < 0) {
	    perror("systemcall error");
	    exit(-1);
	}

	shmflg = 00666 | SHM_RND;
	segm = (struct testStruct *)shmat(shmid, NULL, shmflg);
	if (segm == (void *)-1) {
		perror("Attach wasn't successful!\n");
		exit(-1);
	}
	if (strlen(segm->szoveg) > 0)
		printf("\n %s (%d)",segm->szoveg,segm->hossz);

	printf("\nNew message!\n");
	gets(segm->szoveg);
	printf("%s\n",segm->szoveg);
	segm->hossz=strlen(segm->szoveg);

/* Detach */
	shmdt(segm);
    printf("Szegmens merete: %d\n",buf->shm_segsz);

	exit(0);
}
