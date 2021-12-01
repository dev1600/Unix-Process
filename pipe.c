#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Basically the code read values from one process and another 
// process writes to that value.THis is done through system call
//  called pipe().
int main(int argc,char* argv[])
{
    //below are pointers for 2 file descriptors
    //fd [0] -read
    //fd[1] -write 
    int fd[2];
    if(pipe(fd)==-1)
    {
        printf("An error occured with opening the pipe\n");
        return 1;
    }
    int id=fork();
    if(id==0)
    {
        //also close the read end 

        //usually that is the standard that we close one 
        // "end" of pipe 
        close(fd[0]);
        int x;
        printf("Input a no: ");
        scanf("%d",&x);
        //below takes 2parameters
        //({location were to write the data,},
        // where in the memory to write the data,
        // size of data to be read)

        //similar to file handling operation
        write(fd[1],&x,sizeof(int));
        close(fd[1]);
    } else {
        close(fd[1]);
        int y;
        if(read(fd[0],&y,sizeof(int)) ==-1)
        {
            printf("AN error occured with reading from the pipe\n");
            return 3; 

        }
        close(fd[0]);
        printf("Got from child process %d\n",y);
    }
    return 0;
}