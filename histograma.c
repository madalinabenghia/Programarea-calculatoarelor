#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ASCII_START 48
#define ASCII_END 122

void calculeaza_histograma(const char *input_file, const char *output_file) {
    FILE *fin = fopen(input_file, "r");
    if (!fin) {
        perror("Eroare la deschiderea fisierului de intrare");
        exit(EXIT_FAILURE);
    }

    int frecventa[ASCII_END + 1] = {0};  // Vector pentru stocarea frecvenței caracterelor
    int total_caractere = 0;
    char c;

    // Citire și contorizare caractere
    while ((c = fgetc(fin)) != EOF) {
        if (isalnum(c)) {
            frecventa[(int)c]++;
            total_caractere++;
        }
    }
    fclose(fin);

    // Verificare dacă nu s-au găsit caractere relevante
    if (total_caractere == 0) {
        printf("Fisierul nu contine litere sau cifre relevante.\n");
        return;
    }

    FILE *fout = fopen(output_file, "w");
    if (!fout) {
        perror("Eroare la deschiderea fisierului de iesire");
        exit(EXIT_FAILURE);
    }

    // Afișare histogramă în fișier
    for (int i = ASCII_START; i <= ASCII_END; i++) {
        if (isalnum(i) && frecventa[i] > 0) {
            fprintf(fout, "%c - %.2f%%\n", i, (frecventa[i] * 100.0) / total_caractere);
        }
    }
    fclose(fout);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Nu sunt destule argumente");
        exit(EXIT_FAILURE);
    }

    calculeaza_histograma(argv[1], argv[2]);
    printf("Histograma a fost generata cu succes in %s.\n", argv[2]);

    return EXIT_SUCCESS;
}