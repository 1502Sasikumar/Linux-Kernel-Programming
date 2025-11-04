//shared memory Read.c(using System V)
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<stdlib.h>

#define SHM_SIZE 1024

int main()
{
        key_t key = ftok("shmfile",65);
        int shmid = shmget(key, SHM_SIZE, 0666 |IPC_CREAT);

        char *str =(char*)shmat(shmid,NULL,0);
        strcpy(str,"Hello from shared memory\n");
        printf("Writer: Data is stored in Memory\n");
        shmdt(str);
        return 0;

}
