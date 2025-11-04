//shared memory using POSIX
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/mman.h>

int main()
{
        const char *name="/myshm";
        const int SIZE =1024;

        int shm_fd= shm_open(name,O_CREAT|O_RDWR,0666);
        if(shm_fd==-1){
                perror("shm_open");
                exit(EXIT_FAILURE);
        }

        if(ftruncate(shm_fd,SIZE)==-1){
                perror("ftruncate");
                exit(EXIT_FAILURE);
        }

        void *ptr=mmap(0,SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);
        if(ptr == MAP_FAILED){
                perror("mmap");
                exit(EXIT_FAILURE);
        }
        strncpy((char*)ptr,"Hello from POSIX Writer!",SIZE);
        printf("Writer:%s\n",(char*)ptr);

        sleep(10);

        munmap(ptr,SIZE);
        close(shm_fd);
Type  :qa  and press <Enter> to exit Vim                                                                                               13,17-24      Top

