#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 50
#define MAX_ID 1000

typedef struct {
    char name[MAX_SIZE];
    int id;
}Linie;

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

void byNume(char *nume) {
    BubbleSort(nume, strlen(nume));  
}

void byID(int id) {
    BubbleSort(id, MAX_ID);  
}

Linie *ReadFile(const char *filename, int *size) {
    FILE *fin = fopen(filename, "r");

    if (fin == NULL) {
        perror("Eroare la deschiderea fisierului de intrare");
        exit(EXIT_FAILURE);
    }

    *size = 0;
    char line[100];

    while (fgets(line, sizeof(line), fin)) {
        (*size)++;
    }
    rewind(fin);

    Linie *linii = (Linie *)malloc((*size) * (sizeof(Linie)));

    if (!linii) {
        perror("Eroare la alocarea memoriei");
        fclose(fin);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fgets(line, sizeof(line), fin)) {
        scanf(line, "%s %d", linii[i].name, &linii[i].id);
        i++;
    }

    fclose(fin);
    return linii;
}

void writeFile(const char *filename, Linie *linii, int size, int order) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Eroare la deschiderea fisierului de iesire");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        if (order > 0) {
            fprintf(file, "%s ; %d\n", linii[i].name, linii[i].id);
        } else {
            fprintf(file, "%d ; %s\n", linii[i].id, linii[i].name);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Eroare, nu sut destule argumente");
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    int order = atoi(argv[3]);

    int size;
    Linie *linii = readFile(inputFile, &size);

    if (order > 0) {
        bubbleSortByName(linii, size);
    } else {
        bubbleSortById(linii, size);
    }

    writeFile(outputFile, linii, size, order);

    free(linii);

    printf("Datele au fost procesate si scrise in fisierul de iesire '%s'.\n", outputFile);
    return 0;
}