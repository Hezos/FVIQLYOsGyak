#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGKEY 431KEY

struct msgbuf1{
    long type;
    char mtext[512];
} sendbuf, *msgp;

int main()
{
    int msgid;
    key_t key;
    int msgflg;
    int ret, msgsz;
    key = MSGKEY;
    msgflg = 00666 | IPC_CREAT;
    msgid = msgget(key, msgflg);
    if(msgid == -1){
        printf("Hiba");
        exit(-1);
    }
    printf("message created");
    msgp = &sendbuf;
    msgp->type = 1;
    strcpy(msgp->mtext, "uzenet");
    msgsz = strlen(msgp->mytext)+1;
    ret = msgsnd(msgid,(struct msgbuf*)msgp, msgsz, msgflg);
    strcpy(msgp->mtext,"message");
    msgsz = strlen(msgp->mtext)+1;
    ret = msgsnd(msgid(struct msgbuf*)msgp,msgsz,msgflg);


    exit(0);
}
