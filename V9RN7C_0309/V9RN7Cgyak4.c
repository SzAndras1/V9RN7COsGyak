#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 

int main (void){
        pid_t pid;

        if ((pid = fork()) < 0){
                perror("process error");
        }else if (pid == 0){
                if(execl("./child2", "child2", (char *) NULL) < 0){
                        perror("execl error");
                }
        }
        if (waitpid(pid, NULL, 0) < 0){
                perror("wait error");
        }
        return 0;
}