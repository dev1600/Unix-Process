#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
    int id=fork();
    //ppid is parent process id
    printf("Current Id: %d and  Parent id: %d \n",getpid(),
    getppid());
    return 0;
}