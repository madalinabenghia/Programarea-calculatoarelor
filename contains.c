#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int contains(char *sir, char c)
{
    while (*sir)
    {
        if (*sir == c)
        {
            return 1;
        }
        sir++;
    }
    return 0;
}

void BubbleSort(char *v, int n)
{
	int s,i,aux;
	do{
		s = 0;                             // setam faptul ca nu au avut loc schimbari la iterarea curenta
		for (i = 1; i < n; i++)
		{      
			// @1 - pornim de la 1 ca sa formam perechi (v[i-1],v[i])
			if (v[i - 1] > v[i])
			{             
				// daca valorile NU respecta relatia de ordine
				aux = v[i - 1];                 // interschimba valorile
				v[i - 1] = v[i];
				v[i] = aux;
				s = 1;                             // @2 - seteaza faptul ca a avut loc cel putin o schimbare
			}
		}
	} while (s);                         // daca s adevarat (!=0), atunci repeta iterarea
}

char *intersection(char *str1, char *str2) {
    int ct = 0;

    for(int i = 0; str1[i] != '\0'; i++) {
        if(contains(str2, str1[i]) && !contains(str1, str1[i] + 1)) {
            ct++;
        }
    }

    char *sir_rezultat = (char *)malloc(ct + 1);
    if(sir_rezultat == NULL) {
        printf("Nu se poate deschide fisierul");
        exit(EXIT_FAILURE);
    }

    int index = 0;

    for(int i = 0; str1[i] != '\0'; i++) {
        if(contains(str2, str1[i]) && !contains(str1, str1[i] + 1)) {
            index++;
            sir_rezultat[index] = str1[i];
            break;
        }
    }
    index++;
    sir_rezultat[index] = '\0';

    BubbleSort(sir_rezultat, index);

    return sir_rezultat;
}

int main() {
    char str1[100];
    char str2[100];

    scanf("%s", str1);
    scanf("%s", str2);

    char *rez = intersection(str1, str2);

    printf("Caracterele comune sortate alfabetic: %s\n", rez);

    free(rez);

    return 0;
}
