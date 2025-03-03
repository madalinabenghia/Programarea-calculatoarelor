#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define CHUNK 50
FILE *f=NULL;

typedef struct{
    char judet[50];
    int populatie,beneficiari,suma,alte;
}INDEMNIZATIE;

int procesare(char *text, INDEMNIZATIE *jud)
{
    //am pus pointer la text si judet ca nu stiu ce dimensiune are
    //la examen verific strtok, citirile,alocare,deschidere fisier,...tot
    char *p=NULL;
    if((p=strtok(text,";"))==NULL)
    {
        return 0;
    }
    int i=0;
    uint32_t pop=0; //pt atol sau long pop=0;
    while(p)
    {
        //pt verificare daca afiseaza linia,afisez p sa vad daca imparte linia bine
        //i este indicele coloanei;
        if(i==0)
        {
            memset(jud->judet,0,50);
            strncpy(jud->judet,p,49);
            //daca imi afiseaza s p, afisez jud->jude,bla bla
        }
        //atol e pt long
        //atoi e pt int
        if(i==1)
        {
            pop=atol(p);
            jud->populatie=pop;
        }
        if(i==2)
        {
            jud->beneficiar=atol(p);
        }
        //i==3 nu mai fac ca nu imi cere
        if(i==4)
        {
            jud->suma=atol(p);
        }
        if(i==5)
        {
            jud->altele=atol(p);
        }
        i++;
        if((p=strtok(NULL,";"))=NULL)
        {
            return 1;
        }
    }
    return 0;
}

INDEMNIZATIE *add_jud(INDEMNIZATIE *str, INDEMNIZATIE *jud, int *index) //val modificata pt i
{
    static int al_size=0;
    int i=0;
    if(i==al_size)
    {
        al_size=al_size+CHUNK;
        if(str=realloc(str,al_size*sizeof(INDEMNIZATIE))==NULL)
        {
            exit(-1);
        }
    }
    str[i]=*jud;  //sunt toate,suma,judet,etc ; pastrez adresele fiecarui struct procesat
    //afisez neaparat str[i] pt verificare, daca e bine e maxim o pb la incrementare
    i++;
    *index=i;
    
    return str;
}

void print_judete(INDEMNIZATIE *lista, int n);
{
    for(int i=0;i<n;i++)
    {
        printf("%s %d %d\n",lista[i]->judet,lista[i]->populatie,lista[i]->beneficiari);
    }
}

void read() //nu citesc tot, se foloseste la orice problema
{
    //deschid fisier
    INDEMNIZATIE jud,*lista;
    if(f=fopen("indemnizatie.csv","r")==NULL) //numele fisierului descarcat
    {
        printf("eroare");
        exit(-1);
    }
    char text[SIZE];
    if(fgets(text,SIZE,f)==NULL) //ce citeste din f de mrimea size imi pune in text
    { //mi a citit prima linie si am scapat de ea
        printf("eroare");
        exit(-1);
    }
    int index=0;
    while(fgets(text,SIZE,fin)!=NULL)
    {
        //pt verificare erori afisez linia
       if(procesare(text,&jud)==1)
       {
           //afisae jud pt verificare
           
           lista=add_jud(lista,&jud,&index);
           //afisare
       }
    }
    if(lista=realloc(lista,index*sizeof(INDEMNIZATIE))==NULL)
    {
        exit(-1);
    }
    fclose(f);
    if(close(f)!=0)
    {
        exit(-1);
    }
    print_judete(lista,index);
    free(lista);
}

int main(void) //nu citesc,nu afisez,nu fac chestii in main
{
    read();
}