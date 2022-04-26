#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGKEY 431KEY

struct msgbuf1{
    long type;
    char[512];
}recbuf,*msgp;

struct msgid_ds, *buf;

int main(){
    int msgid;
    key_t key;
    int mtype, msgflg;
    int ret, msgsz;

    key = MSGKEY;
    msgflg = 00666 | IPC_Create | MSG_NOERROR;
    msgid = msgget(key, msgflg);
    if(msgid == -1){
        printf("Hiba");
    }
    msgp = &recbuf;
    buf = &ds;
    msgsz = 20;
    mytype = 0;
    ret = msgctl(msgid, IPC_STAT, buf);
    while(buf-> msg_qnum){
        ret = msgrcv(msgid,(struct msgbuf*)msgp, msgsz, mtype, msgflg);
        ret = msgctl(msgid, IPC_SZAT, buf);
    }

    exit(0);
}
