#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

# FileNeve "FVIQLY.txt"

void ír();

int main(void)
{
    int NotSigned;
    ír();
    int ret, fd;
    char buf[32];
    buf[0] = 0;
    fd = open("fájl.txt", O_RDWR);
    printf("%d", write(fd,buf,32));
    fd = open("fájl.txt", O_RDWR);
    if(fd == -1){
        printf("Hiba olvasásnál");
    }
    ret = read(fd, buf, 32);
    printf("%d", ret);
    fd = open("fájl.txt", O_RDWR);
    printf("%d",lseek(SEEK_SET,fd,32));


    return 0;
}

void ír(){
    FILE* fp = open("wt", FileNeve);
    fprintf(fp, "%s","Nagy Bence, mérnökinformatikus, FVIQLY");
    return;
}

