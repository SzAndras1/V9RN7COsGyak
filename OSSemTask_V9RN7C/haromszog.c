#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void){
	int fd;
	char buf[20];
	pid_t p;
	p=fork();	
	
	if(p<0)
	{
		fprintf(stderr, "fork Failed");
		return 1;
	}
	//parent
	else if(p > 0)
	{	
		
		fd = open("v9rn7c", O_RDONLY);
		read(fd, buf, 20);
		int opening = 0;
		if((opening=open("kimenet.txt", O_RDWR)) < 0){
			printf("Nincs ilyen fajl!\n");
			return -1;
		}
		write(opening, buf, strlen(buf)+1);
		close(opening);
		close(fd);
	}
	//child
	else
	{
		char content[25];
		int opening = 0;
		if((opening=open("bemenet.txt", O_RDWR)) < 0){
			printf("Nincs ilyen fajl!\n");
			return -1;
		}
	
		int sizeOfTxt = read(opening, content, sizeof(content));
		content[sizeOfTxt] = '\0';
		
		int leptet = 0;
		int szokoz[2];
		for(int i = 0;i<strlen(content);i++){
			if(content[i] == ' '){
				szokoz[leptet] = i;
				leptet++;
			}
		}

		int elso_szokoz = szokoz[0];
		int mas_szokoz = szokoz[1];
	
		char aOldal[elso_szokoz];

		int bOldal_seged = mas_szokoz - elso_szokoz - 1;
		char bOldal[bOldal_seged];
		int cOldal_seged = strlen(content) - mas_szokoz - 1;
		char cOldal[cOldal_seged];
	
		for(int i = 0;i<elso_szokoz;i++){
			aOldal[i] = content[i];
		}
	
		int seged = 0;
		for(int i = elso_szokoz+1;i<mas_szokoz;i++){
			bOldal[seged] = content[i];
			seged++;
		}
	
		seged = 0;
		for(int i = mas_szokoz+1;i<strlen(content);i++){
			cOldal[seged] = content[i];
			seged++;
		}
		float a = atof(aOldal);
		float b = atof(bOldal);
		float c = atof(cOldal);
		char kiiras[20] = "";
		strcat(kiiras, content);
	
		if((a + b > c)&&(b + c > a)&&(c + a > b))
			strcat(kiiras, " 1");
		else
			strcat(kiiras, " 0");
		
		fd = open("v9rn7c", O_WRONLY);
		write(fd, kiiras, strlen(kiiras)+1);
		close(opening);
		close(fd);

	}
	return 0;

}
