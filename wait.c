#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
int main(int argc,char* argv[]){
    int id=fork();
    int n;
    if(id==0)
    {
        n=1;
    }
    else {
        n=6;
    }
    // A call to wait() blocks the calling process until one of its child processes exits or a signal is received.
//  After child process terminates, parent continues its execution after wait system call instruction. 
// Child process may terminate due to any of these: 

//     It calls exit();
//     It returns (an int) from main
//     It receives a signal (from the OS or another process) whose default action is to terminate.

    if(id !=0)
    {
        wait();
    }
    int i;
    //the order of printing no is not definite hence 
    // we make use of wait function
    for(int i=n;i<n+5;i++)
    {
        printf("%d ",i);
        fflush(stdout);
    }
    printf("\n");
}