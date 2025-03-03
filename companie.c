#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char nume[20];
    float buget, profit;
}companie;


int main(void)
{
    companie *c=NULL;
    //c=malloc(sizeof(int));
    int n;
    int i=0;
    float p;
    while(1)
    {
        scanf("%d",&n);
        switch(n)
        {
            case 0:
            {
                free(c);
                return 0;
            }
            case 1:
            {
                i++;
                if((c=(companie*)realloc(c,i*sizeof(companie))) == NULL)
                {
                    printf("eroare");
                    exit(-1);
                }
                //c=(companie*)(realloc(c,i*(sizeof(companie))))
                printf("adaugati compania: ");
                scanf("%s",c[i-1].nume);
                scanf("%f",&c[i-1].buget);
                c[i-1].profit=0.1*c[i-1].buget;
                printf("\n");
                break;
            }
            case 2:
            {
                printf("\n");
                for(int j=0;j<i-1;j++)
                {
                    for(int p=j+1;p<i;p++)
                        if(strcmp(c[j].nume,c[p].nume)<0)
                        {
                            companie aux=c[j];
                            c[j]=c[p];
                            c[p]=aux;
                            
                        }
                }
                
                for(int j=0;j<i;j++)
                {
                    printf("%s\n",c[j].nume);
                }
                printf("\n");
                break;
                
            }
            case 3:
            {
                printf("test1");
                printf("profitul dat de utilizator:");
                scanf("%f",&p); //profitul
                for(int j=0;j<i;j++)
                {
                    if(c[j].profit>p)
                    {
                        printf("%f ",c[j].profit);
                    }
                }
                break;
                printf("\n");
            }
            case 4:
            {
                printf("\n");
                for(int j=0;j<i;j++)
                {
                    printf("compania %d :",j);
                    int k,nrb=0;
                    k=strlen(c[j].nume);
                    for(int p=7;p>=0;p--)
                    {
                        if((k>>p)&1)
                        {
                            nrb++;
                        }
                    }
                    printf("%d ",nrb);
                }
                
                break;
            }
        }
    }
    return 0;
}

