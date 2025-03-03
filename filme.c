#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 50
#define SIZE 1000

FILE *f=NULL;

typedef struct{
    char titlu[50];
    int an;
    float buget;
}FILM;

int procesare(char *text, FILM *v)
{
    char *p=NULL;
    if((p=strtok(text,","))==NULL)
    {
        return 0; //eroare 3
    }
    int i=0;
    //uint8_t an2=0;
    while(p)
    {
        //an
        if(i==0)
        {
            /*an2=atoi(p);
            v->an=an2;*/
            v->an=atoi(p);
        }
        if(i==2)
        {
            memset(v->titlu,0,50);
            strncpy(v->titlu,p,49);
        }
        if(i==6)
        {
            v->buget=atol(p);
        }
        i++;
        if((p=strtok(NULL,","))==NULL)
        {
            return 1;
        }
    }
    return 0;
}

FILM *add_v(FILM *str, FILM *v, int *index)
{
    static int al_size=0;
    int i=0;
    if(i==al_size)
    {
        al_size=al_size+CHUNK;
        if(str=realloc(str,al_size*sizeof(FILM))==NULL)
        {
            //eroare 4
            exit(-1);
        }
    }
    str[i]=*v;
    i++;
    *index=i;
    return str;
}

void read()
{
    FILM *v, *lista;
    if(f=fopen("movies.cxv","r")==NULL)
    {
        printf("eroare1");
        exit(-1);
    }
    char text[SIZE];
    if(fgets(text,SIZE,f)==NULL)
    {
        printf("eroare2");
        exit(-1);
    }
    
    while(fgets(text,SIZE,f)!=NULL)
    {
        if(procesare(text,&v)==1)
        {
            lista=add_v(lista,&v,&index);
        }
    }
    if(lista=realloc(lista,index*sizeof(FILM))==NULL)
    {
        //eroare 5
        exit(-1);
    }
    //fclose(f);
    if(fclose(f)!=0)
    {
        exit(-1);
    }
    print_filme(lista,index);
    free(lista);
}