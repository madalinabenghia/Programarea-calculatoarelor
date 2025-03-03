#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 50
#define SIZE 1000

FILE *f=NULL,*f1=NULL,*f2=NULL,*f3=NULL;

typedef struct{
    char titlu[50];
    long buget,an;
}FILM;

int nrfilme=0;
FILM **filme=NULL;
void sortare(int l)
{
    FILM *aux=NULL;
    for(int i=0;i<nrfilme-1;i++)
    {
        for(int j=i+1;j<nrfilme;i++)
        {
            if(l==0)
            {
                if(filme[i]->an > filme[j]->an)
                {
                    aux=filme[i];
                    filme[i]=filme[j];
                    filme[j]=aux;
                }
            }
            if(l==1)
            {
                if(strcmp(filme[i]->titlu,filme[j]->titlu)>0)
                {
                    aux=filme[i];
                    filme[i]=filme[j];
                    filme[j]=aux;
                }
            }
            if(l==6)
            {
                if(filme[i]->buget > filme[j]->buget)
                {
                    aux=filme[i];
                    filme[i]=filme[j];
                    filme[j]=aux;
                }
            }
        }
    }
}

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
        if((str=realloc(str,al_size*sizeof(FILM)))==NULL)
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
    if((f=fopen("movies.cxv","r"))==NULL)
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
        if(procesare(text,v)==1)
        {
            lista=add_v(lista,v,&(index));
        }
        nrfilme++;
    }
    if((lista=realloc(lista,(index)*sizeof(FILM)))==NULL)
    {
        //eroare 5
        exit(-1);
    }
    //fclose(f);
    if(fclose(f)!=0)
    {
        exit(-1);
    }
    //print_filme(lista,index);
    free(lista);
}



int main(void)
{
    read();
    if((f1=fopen("out1.txt","w+"))==NULL)
    {
        printf("eroare6");
        exit(-1);
    }
    sortare(0);
    
    for(int i=0;i<nrfilme;i++)
    {
        fprintf(f1,"%s\t%ld\t%ld\n",filme[i]->titlu,filme[i]->an,filme[i]->buget);
    }
    fclose(f1);
    
    if((f2=fopen("out1.txt","w+"))==NULL)
    {
        printf("eroare7");
        exit(-1);
    }
    sortare(2);
    for(int i=0;i<nrfilme;i++)
    {
        fprintf(f2,"%s\t%ld\t%ld\n",filme[i]->titlu,filme[i]->an,filme[i]->buget);
    }
    fclose(f2);
    
    if((f3=fopen("out1.txt","w+"))==NULL)
    {
        printf("eroare8");
        exit(-1);
    }
    sortare(6);
    for(int i=0;i<nrfilme;i++)
    {
        fprintf(f3,"%s\t%ld\t%ld\n",filme[i]->titlu,filme[i]->an,filme[i]->buget);
    }
    fclose(f3);
    
}





































PB 1 LAB 13 MODIFICATA CU O EROARE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 50
#define SIZE 1000

FILE *f=NULL,*f1=NULL,*f2=NULL,*f3=NULL;

typedef struct{
    char titlu[50];
    long buget,an;
}FILM;

int nrfilme=0;
FILM **filme=NULL;
void sortare(int l)
{
    FILM *aux=NULL;
    for(int i=0;i<nrfilme-1;i++)
    {
        for(int j=i+1;j<nrfilme;j++)
        {
            if(l==0)
            {
                if(filme[i]->an > filme[j]->an)
                {
                    aux=filme[i];
                    filme[i]=filme[j];
                    filme[j]=aux;
                }
            }
            if(l==1)
            {
                if(strcmp(filme[i]->titlu,filme[j]->titlu)>0)
                {
                    aux=filme[i];
                    filme[i]=filme[j];
                    filme[j]=aux;
                }
            }
            if(l==6)
            {
                if(filme[i]->buget > filme[j]->buget)
                {
                    aux=filme[i];
                    filme[i]=filme[j];
                    filme[j]=aux;
                }
            }
        }
    }
}

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
        if((str=realloc(str,al_size*sizeof(FILM)))==NULL)
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
    int index;
    if((f=fopen("movies.csv","r"))==NULL)
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
        if((v=malloc(sizeof(FILM)))==NULL)
        {
            printf("eroare malloc");
            exit(-1);
        }
        if(procesare(text,v)==1)
        {
            lista=add_v(lista,v,&index);
        }
        nrfilme++;
    }
    if((lista=realloc(lista,index*sizeof(FILM)))==NULL)
    {
        //eroare 5
        exit(-1);
    }
    //fclose(f);
    if(fclose(f)!=0)
    {
        exit(-1);
    }
    //print_filme(lista,index);
    free(lista);
    free(v);
}

int main(void)
{
    read();
    if((f1=fopen("out1.txt","w+"))==NULL)
    {
        printf("eroare6");
        exit(-1);
    }
    sortare(0);
    
    for(int i=0;i<nrfilme;i++)
    {
        fprintf(f1,"%s\t%ld\t%ld\n",filme[i]->titlu,filme[i]->an,filme[i]->buget);
    }
    fclose(f1);
    
    if((f2=fopen("out1.txt","w+"))==NULL)
    {
        printf("eroare7");
        exit(-1);
    }
    sortare(2);
    for(int i=0;i<nrfilme;i++)
    {
        fprintf(f2,"%s\t%ld\t%ld\n",filme[i]->titlu,filme[i]->an,filme[i]->buget);
    }
    fclose(f2);
    
    if((f3=fopen("out1.txt","w+"))==NULL)
    {
        printf("eroare8");
        exit(-1);
    }
    sortare(6);
    for(int i=0;i<nrfilme;i++)
    {
        fprintf(f3,"%s\t%ld\t%ld\n",filme[i]->titlu,filme[i]->an,filme[i]->buget);
    }
    fclose(f3);
    
}