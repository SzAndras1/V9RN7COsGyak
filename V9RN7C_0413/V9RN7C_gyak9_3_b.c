#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

void AlarmHandler(int sig);

int main(void){
    if (signal(SIGALRM, AlarmHandler) == SIG_ERR){
        printf("Nem sikerult handlert allitani a(z) \"SIGALRM\" jelre!\n");
        return 1;
    }
    pause();
    return 0;
}

void AlarmHandler(int sig){
    printf("V9RN7C\nMost már nincs block, terminálódok!\n");
    exit(1);
}