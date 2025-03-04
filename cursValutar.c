#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char data[11];
    float curs_valutar;
} Linie;

Linie *ReadFile(const char *filename, int *size) {
    FILE *fin = fopen(filename, "r");

    if (fin == NULL) {
        perror("Eroare la deschiderea fisierului de intrare");
        exit(EXIT_FAILURE);
    }

    *size = 0;
    char line[100];

    fgets(line, sizeof(line), fin);
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

    fgets(line, sizeof(line), fin);

    int index=0;
    
    while (fgets(line, sizeof(line), fin)) {
        char *token = strtok(line, ";");
        if(token != NULL) {
            strncpy(linii[index].data, token, sizeof((linii[index].data))-1);
            //      aici vrem sa copiem(aicile punem), ce sa copiem (de aici le luam), cat sa copiem -size-ul
            linii[index].data[sizeof(linii[index].data) - 1] = '\0';
        }

        token = strtok(NULL, ";");
        if(token != NULL) {
            linii[index].curs_valutar = atof(token);
        }
        index++;
    }

    fclose(fin);
    return linii;
}

void writeFile(const char *filename, Linie *linii, int size) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Eroare la deschiderea fisierului de iesire");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < size; i++) {
        fprintf(file, "%s;%.4lf\n", linii[i].data, linii[i].curs_valutar);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("eroare");
        return 1;
    }

    const char *fisier_intrare = argv[1];
    const char *fisier_iesire = argv[2];

    int size;

    Linie *linii = ReadFile(fisier_intrare, &size);
    writeFile(fisier_iesire, linii, size);

    free(linii);
    return 0;
}