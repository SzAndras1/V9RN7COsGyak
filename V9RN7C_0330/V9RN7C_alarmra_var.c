#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(void);

int main(void)
{
	signal(SIGALRM, (void (*)()) handler);
	printf("\n Várakozni kezdek ... \n");
	pause( );
	
	printf(" Kibillentem a várakozásból. \n");
	exit(0);
}

void handler(void) {;}