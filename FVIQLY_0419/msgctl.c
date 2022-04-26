#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGKEY 431KEY

main(){

    int msgid, msgflf, ret;
    key_t key;
    key = MSGKEY;
    msgflg = msgget(key, msgflg);
    ret = msgctl(msgid,IPC_RMID, NULL);

    exit(0);
}
