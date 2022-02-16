#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

    char *args[]={"./EXEC",'a',NULL};
    execvp(args[0],args);

    printf("Ending...\n");
    // When the file execDemo.c is compiled, as soon as the
    // statement execvp(args[0],args) is executed, this 
    // very program is replaced by the program EXEC.c. 
    // “Ending—–” is not printed because because as soon 
    // as the execvp() function is called, this program is
    //  replaced by the program EXEC.c.
    return 0;
}