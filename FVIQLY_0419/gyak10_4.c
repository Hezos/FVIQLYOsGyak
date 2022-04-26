#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>
#include <sys/msg.h>

#define MSGKEY 431KEY

struct msgbuf1{
    long mytype;
    char mtext[512];
} sendbuf, *msgp;

struct msgbuf1 {
	long mtype;
	char mtext[512];
} recvbuf, *msgp;

struct msqid_ds ds, *buf;

main(){
    int msgid;
    int mtype;
    key_t key;
    int msgflg;
    int ret, msgsz;
    key = MSGKEY;
    msgflg = 00666 | IPC_CREATE;
    msgid = msgget(key, msgflg);
    if(msgid == -1){
        printf("hiba");
        exit(-1);
    }
    msgp = &sendbuf;
    msgp->mytype = 1;
    strcpy(msgp->mytype,"message");
    msgsz = strlen(msgp->mtext)-1;
    while(exit(0) != 1){
        ret = msgsnd(msgid,(struct msgbuf *)msgp,
                     msgsz, msgflg);
    }
    printf("%d",ret);

    ret=mkfifo("receiver",00666);
	if (ret == -1) {
	    perror("mkfifo()");
	    exit(-1);
	}

	fd=open("receiver",O_RDWR);
	if (fd == -1) {
	    perror("open() hiba!");
	    exit(-1);
	}else{
        msgp = &recvbuf;
        buf = &ds;
        msgsz = 20;
        mtype = 0;
        ret = msgctl(msgid, IPC_STAT, buf);
        printf("Az uzenetek szama az uzenetsorban: %d\n", buf->msg_qnum);

	}




    exit(0);
}
