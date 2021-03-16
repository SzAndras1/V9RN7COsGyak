#include <stdio.h>
void exit(int status);
#include <stdlib.h>
void abort(void);
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
	pid_t pid;
	int status;
	if ((pid = fork()) < 0) perror("fork hiba");
		else if (pid == 0) /* gyermek */
			exit(7);/* befejeződik */
	if (wait(&status) != pid) perror("wait hiba"); /* szülő */
	if (WIFEXITED(status))
		printf("Normális befejeződés, visszaadott érték = %d\n", WEXITSTATUS(status));
	if ( (pid = fork()) < 0) perror("fork hiba");
		else if (pid == 0)
			abort();
	if (wait(&status) != pid) perror("wait hiba");
	if (WIFSIGNALED(status))
		printf("Abnormális befejeződés, a szignál sorszmáma = %d\n", WTERMSIG(status));
	int elso, ketto;
	scanf("%d %d", &elso, &ketto);
	if(ketto == 0){
		if ( (pid = fork()) < 0) perror("fork hiba");
			else if (pid == 0)
				abort();
		if (wait(&status) != pid) perror("wait hiba");
		printf("Nem megengedett művelet a nullával való osztás.");
	}
	else
		printf("%d / %d = %f", elso, ketto, (float)elso/ketto);
}