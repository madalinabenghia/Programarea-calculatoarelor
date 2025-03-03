//pb 7
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    int v[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(v[j]%2==0)
            {
                int aux=v[j];
                v[j]=v[i];
                v[i]=aux;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    return 0;
}




//pb 8
#include <stdio.h>
//v=1 2 3 4 5 => v=1 
//v= 7 6 5 4 9 =>v=9
int main(void)
{
    int n;
    scanf("%d",&n);
    
    int v[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        if(v[i]<v[i+1])
        {
            for(int j=i;j<n;j++)
            {
                v[j]=v[j+1];
            }
            n--;
            i--;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    return 0;
}



//pb9
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int v[n+n/2]; // dimensiunea maxima a vectorului este de 3/2*n
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++) {
        if (v[i] % 2 != 0) {
            for (int j = n-1; j >= i; j--) {
                v[j+1] = v[j];
            }
            v[i] = 0;
            n++; // marim dimensiunea vectorului
            i++; // trecem peste 0-ul pe care l-am inserat
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    
    return 0;
}



//PB 10
#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    int v[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        if(v[i]<0)
        {
            for(int j=i;j<n;j++)
            {
                int aux=v[j+1];
                v[j+1]=v[j];
                v[j]=aux;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    return 0;
}




//pb 11
#include <stdio.h>
int n;
int stergere(int v[],int n,int j)
{
    for(int p=j;p<n;p++)
        {
            v[p]=v[p+1];
        }
    n--;
    return n;
}
int main(void)
{
    scanf("%d",&n);
    int v[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(v[i]==v[j])
            {
                n=stergere(v,n,j);
                j--;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    return 0;
}





























#include <stdio.h>

typedef struct{
    char nume[20];
    float buget, profit;
}companie;

int profit(float v[],)

int main(void)
{
    companie c[100];
    int n;
    scanf("%d",&n);
    int i=0;
    switch(n)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            scanf("%d",&c.nume[i]);
            scanf("%f",&c.buget[i]);
            scanf("%f",&c.profit[i]);
            i++;
            break;
        }
        case 2:
        {
            for(int j=0;j<i;j++)
            {
                if(strcmp(c.nume[j][0],c.nume[j+1][0])<0))
                {
                    char aux=c.nume[j];
                    c.nume[j]=c.nume[j+1];
                    c.nume[j+1]=aux;
                    j--;
                }
            }
            
            for(int j=0;j<i;j++)
            {
                printf("%s\n",c.nume[j]);
            }
            break;
        }
        case 3:
        {
            int p;
            scanf("profitul dat de utilizator: %f",&p); //profitul
            for(int j=0;j<i;j++)
            {
                
            }
        }
    }
}






