#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


// Using this command, the created child process does not 
// have to run the same program as the parent process does. 
// The exec type system calls allow a process to run any 
// program files, which include a binary executable or a shell script . 
// Syntax:
//     int execvp (const char *file, char *const argv[]);

// file: points to the file name associated with the file being executed.
// argv:  is a null terminated array of character pointers.


int main()
{
    int i;
    // printf("No from other porgram %d",argv[0][0]);
    printf("Program being called by execvp()\n");
    return 0;
}