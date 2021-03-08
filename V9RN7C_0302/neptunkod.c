#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct adatok{
    char nev[20];
    char szak[10];
    char neptunkod[7];
}Adatok;

void filebakiir(Adatok* e, int meret);
void beolvas(Adatok* e, int meret);
int hanytanulo(int* meret);
void filebolkiolvas();

int main()
{
    int meret;
    hanytanulo(&meret);
    Adatok lista[meret];
    beolvas(lista, meret);
    filebakiir(lista, meret);
    filebolkiolvas();
    return 0;
}

int hanytanulo(int* meret){
    char ch;
    int ok = 1;
    do{
        ok = 1;
        printf("Hany tanulo van? ");
        if(scanf("%d", meret)!=1){
            printf("Hibas input!\n");
            ok = 0;
            while((ch=getchar()!='\n'));
        }
    }while(!ok || *meret < 0);
    return *meret;
}

void beolvas(Adatok* e, int meret){
    for(int i = 0; i<meret;i++){
        printf("Tanulo neve: ");
        scanf("%s", e[i].nev);
        printf("Szak: ");
        scanf("%s", e[i].szak);
        printf("Neptunkod: ");
        scanf("%s", e[i].neptunkod);
    }
    return ;
}
void filebakiir(Adatok* e, int meret){
    FILE *fp;
    fp = fopen("vezeteknev.txt", "wt");
    if(!fp){
        printf("Error: cannot open file."); return;
    }
    for(int i=0;i<meret;i++)
        fprintf(fp, "%s %s %s\n", e[i].nev, e[i].szak, e[i].neptunkod);
    fclose(fp);
    return ;
}

void filebolkiolvas(){
    FILE *fp;
    fp = fopen("vezeteknev.txt", "rt");
    if(!fp){
        printf("Error: cannot open file."); return ;
    }
    Adatok uj;
    char ch;
    int number_of_lines=0;
    while((ch = fgetc(fp)) != EOF){
        if(ch == '\n')  number_of_lines++;
    }
    if (number_of_lines==0){
            printf("\nFile is empty ...\n");  return ;
    }
    rewind(fp);
    for(int i = 0; i<number_of_lines;i++){
        fscanf(fp, "%s %s %s", uj.nev, uj.szak, uj.neptunkod);
        printf("\nNev: %s, Szak: %s, Neptunkod: %s", uj.nev,uj.szak, uj.neptunkod);
    }
    fclose(fp);
    return ;
}
