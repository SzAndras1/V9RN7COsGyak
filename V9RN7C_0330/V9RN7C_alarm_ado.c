#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char **argv){
	pid_t pid; 
	if(argc < 1) {
		printf(" \n Nincs kinek. \n");
		exit(1);
	}
	pid = atoi(argv[1]); 
	kill(pid, SIGALRM);
	exit(0);	
}