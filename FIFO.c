#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc,char * argv[])
{
    // in pipes we can't have two process communicate with each
    // other if they are not in the same heirarchy hence we use FIFO
    
    // we are creating a FIFO named pipe
    // here we need to specify path along with name
    // and we need to specify the permission
    
    //the below snippet will create a file named myfifo
    // in the same directory 

    //mkfifo returns -1 if it is not able to create the file
    // else returns 0 means everything is fine
    //here EEXIST tells that 
    
    if(mkfifo("myfifo",0777) ==-1){

        // EEXIST tell us if error is because file already exist
        if(errno !=EEXIST){
            printf("Could not create fifo file\n");
            return 1;
        }
    }
    
    //open 2nd parameter tells us what purpose we open the file
    printf("Opening...\n");
    int fd=open("myfifo", O_WRONLY);//returns file descriptor
    int x=97;
    printf("Opened\n");
    //Open does not start writing till there is another process or thread
    //which is open for reading.
    printf("Writing file....\n");
    if(write(fd,&x,sizeof(x))== -1){
        return 2;
    }
    printf("Closing....\n");
    close(fd);
    printf("Closed\n");
    
    return 0;
}