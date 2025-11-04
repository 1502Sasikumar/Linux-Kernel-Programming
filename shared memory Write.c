//shared memory write.c program
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<stdlib.h>

#define SHM_SIZE 1024

int main()
{
    key_t key = ftok("shmfile",65);
    int shmid = shmget(key,SHM_SIZE,0666|IPC_CREAT);
    
    char *str = (char*)shmat(shmid,NULL,0);
    strcpy(str, "Hello from shared memory!");
    printf("Writer: Data returned to shared memory\n");
    shmdt(str);
    return 0;
}
