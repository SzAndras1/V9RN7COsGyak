#include <stdlib.h>
#include <stdio.h>
int system(const char *command);
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int status;

	if((status = system("date"))<0)
        perror("system() error");
	if(WIFEXITED(status))
		printf("Normalis befejezodes, visszaadott ertek = %d\n", WEXITSTATUS(status));
	exit(0);
}
