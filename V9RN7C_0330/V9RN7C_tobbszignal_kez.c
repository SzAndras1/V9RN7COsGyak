#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void interruptHandler(int);
void quitHandler(int);
void sigIntError();
void sigQuitError();
void waiting();

unsigned int Interrupts = 0;

int main(){
	sigIntError();
	sigQuitError();
	waiting();
	printf("Megerkezett a masodik \"SIGINT\" jel!\n");
    	return 0;
}

void interruptHandler(int sig){
   	printf("\nSIGINT signal: %d\n", sig);
    	Interrupts++;
}

void quitHandler(int sig){
    	printf("\nSIGQUIT signal: %d\n", sig);
}

void waiting(){
	while(Interrupts < 2){
        	printf("Varok a jelre...\n");
        	sleep(1);
	}
}

void sigIntError(){
	if (signal(SIGINT, interruptHandler) == SIG_ERR){
        	printf("Hiba tortent!\n");
        	exit(0);
     }
}

void sigQuitError(){
	if (signal(SIGQUIT, quitHandler) == SIG_ERR){
       	 printf("Hiba tortent!\n");
       	 exit(0);
     }

}

