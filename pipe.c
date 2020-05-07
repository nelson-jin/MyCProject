#include<stdio.h>
#include<unistd.h>

int main(int arg, char *args[])
{
    int n,fd[2];
    int pid;
    char line[1024];
    if(pipe(fd) < 0)
    {
        printf("pipe error\n");
        exit(-1);
    }
    if((pid = fork()) < 0)
    {

    }
    else if(pid == 0)
    {
        close(fd[0]);
        write(fd[1],"hello world\n",12);
    }
    else
    {
        close(fd[1]);
        n = read(fd[0],line,1024);
        write(STDOUT_FILENO, line, n);
    }
    
    exit(0);
}