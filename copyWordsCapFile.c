#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void copy_words_cap(char *source_file_path, char *destination_file_path) {
    FILE *fin = fopen(source_file_path, "r");
    if(fin == NULL) {
        printf("Nu se poate deschide fisierul");
        exit(EXIT_FAILURE);
    }
        //printf("test4\n");


    FILE *fout = fopen(destination_file_path, "w");
    if(fout == NULL) {
        printf("Nu se poate deschide fisierul");
        exit(EXIT_FAILURE);
    }
        //printf("test5\n");


    char word[MAX_SIZE];
    while(fscanf(fin, "%s", word)==1) {
           // printf("test while\n");

        if(isalpha(word[0])) {
            word[0] = toupper(word[0]);
        }
            //printf("test  scriere\n");

        fprintf(fout, "%s ", word);
    }

    //printf("test\n");

    fclose(fin);
    fclose(fout);
}

int main() {
    char *fin = "random_text.txt";
    char *fout = "output.txt";
        //printf("test2\n");


    copy_words_cap(fin, fout);
        //printf("test3\n");

    printf("Cuvintele au fost procesate si scrise in fisierul destinatie '%s'.\n", fout);
    return 0;
}