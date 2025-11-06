//PIPE program
#include<stdlib.h>
#include<stdio.h>
int main()
{
        int fd[2],count=0;
        char ch ='a';

        pipe(fd);
        printf("Writing the pipe..\n");
        while(write(fd[1],&ch,1)>0){
                count++;
                printf("count of pipe:%d\n",count);
                break;
        }
}
