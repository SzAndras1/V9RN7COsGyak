#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main (void) {
        printf("Mit irjak ki? ");
	char command[10];
	char fixcommand[3][10];
	//fgets(command, sizeof command, stdin);
	scanf("%[^\n]s", command);
	int spaces = 0;
	//printf("%s", command);
	for(int i = 0;i<strlen(command);i++){
		if(command[i] == ' ')
			spaces++;
	}
	if(spaces==1){
        	int j=0; int ctr=0;
        	for(int i = 0;i<=strlen(command);i++){
           		if(command[i] == ' ' || command[i] =='\0'){
                		fixcommand[ctr][j]='\0';
                		ctr++;
               			j=0;
           		}
            		else{
                		fixcommand[ctr][j]=command[i];
                		j++;
            		}
        	}
		//printf("%s\n%s", fixcommand[0], fixcommand[1]);
		execlp(fixcommand[0], fixcommand[0], fixcommand[1], (char *)NULL);
	}
	else{
		//printf("%s",command);
		execlp(command, command, (char *)NULL);
	}
	return 0;
}
