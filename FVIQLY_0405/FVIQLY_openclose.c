#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

# FileNeve "FVIQLY.txt"

void �r();

int main(void)
{
    int NotSigned;
    �r();
    int ret, fd;
    char buf[32];
    buf[0] = 0;
    fd = open("f�jl.txt", O_RDWR);
    printf("%d", write(fd,buf,32));
    fd = open("f�jl.txt", O_RDWR);
    if(fd == -1){
        printf("Hiba olvas�sn�l");
    }
    ret = read(fd, buf, 32);
    printf("%d", ret);
    fd = open("f�jl.txt", O_RDWR);
    printf("%d",lseek(SEEK_SET,fd,32));


    return 0;
}

void �r(){
    FILE* fp = open("wt", FileNeve);
    fprintf(fp, "%s","Nagy Bence, m�rn�kinformatikus, FVIQLY");
    return;
}

