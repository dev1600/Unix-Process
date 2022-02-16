#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    //IN this we use two pipes one for child -> Parent 
    // and other for Parent -> Child 
    //In the program we read x from child then modify its 
    //value and send it back to parent.
    // NOTE : p[0] -> read 
    //        p[1] -> write
    //          Writes to => Read By
    int p1[2]; //C => P means Parent reads from child
    int p2[2]; //P =>C means Child reads from Parent

    if(pipe(p1) == -1){ return 1;}
    if(pipe(p2) == -1){ return 1; }

    int pid=fork();
    if(pid == -1){ return 2; }

    if(pid == 0)
    {
        //Since we are not writing data to P2 and reading from
        // Pi we can close them 
        close(p1[0]);
        close(p2[1]);
        int x;
        if(read(p2[0],&x,sizeof(int))==-1){ return 3;}
        printf("Recieved %d\n",x);

        x*=4;

        if(write(p1[1],&x,sizeof(x)) == -1){ return 4;}
        printf("Wrote %d\n",x);

        close(p1[1]);
        close(p2[0]);

    }
    else {
        close(p2[0]);
        close(p1[1]);

        srand(time(NULL));//used to genrate different no.everytime program is executed
        int y=rand()%10;

        if(write(p2[1],&y,sizeof(int))==-1){return 5;}
        printf("Y sent %d\n",y);

        if(read(p1[0],&y,sizeof(int))==-1){ return 6;}
        printf("Y value read %d\n",y);

        close(p2[1]);
        close(p1[0]);
        wait(NULL);
    }


}