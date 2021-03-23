#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
	char content[80];
	int opening = 0;
	if((opening=open("V9RN7C.txt", O_RDWR)) < 0){
		printf("Nincs ilyen fajl!\n");
		return -1;
	}

	int sizeOfTxt = read(opening, content, sizeof(content));

	/*if(sizeOfTxt > sizeof(content)){
		write(2, "Hiba, tul sok karakter!\n", sizeof(content));
		return -1;
	}mert mindig annyi karakter vesz fel, amennyi előre van definiálva a string méreténél, ezért ez felesleges.
	*/
	content[sizeOfTxt] = '\0';
	printf("txt content: \"%s\"\nbyteok szama: %d\n", content, sizeOfTxt);

	lseek(opening, 0, SEEK_SET);
	printf("A txt elejen van a mutato.\n");

	char addition[] = "Hozza lett adva a szoveghez";
	int add_new = write(opening, addition, sizeof(addition));
	printf("Ezt adtuk hozza a szoveg elejehez: \"%s\"\nbyteok szama: %d\n", addition, add_new);

	close(opening);

	return 0;	
}