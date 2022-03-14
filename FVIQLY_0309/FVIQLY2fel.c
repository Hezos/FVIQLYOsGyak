#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#include <unistd.h>

int main()
{
  int status;
  int ok = 0;
    char beolvasott[4];
        if(scanf("%s",beolvasott) == 1){
            ok = 1;
        }
    status = system(beolvasott);
    if(WIFEXITED(status)){
        printf("Visszaadott érték:%d", WEXITSTATUS(status));
    }
	return 0;
}