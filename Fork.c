#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int id=fork();//returns id of process 
    //id of child process is gonna be 0
    //every process in linux or windows has a process id
    fork();
    if(id ==0)
    {
        printf("Hello from child process id=%d\n",id);
    }
   else  printf("Hello world id=%d \n",id);
    return 0;
}