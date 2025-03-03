//3
/*: Se da un tablou de numere intregi pe 16 biti fără semn. Sa se implementeze o functie char *arraytostr(uint16_t *array, int size)
avand ca parametri tabloul si dimensiunea sa care returneaza un string alocat dinamic care sa contina numerele din tablou scrise în binar,
separate prin spațiu. Se va aloca minimul necesar de memorie, iar pentru testare se va defini dimensiunea maxima a tabloului printr-un 
macro iar tabloul va fi populat cu numere aleatoare din intervalul [0, 500000]. Programul se va termina fara memory leaks.
De exemplu pentru tabloul {12, 200, 123, 1, 700} de dimensiune 5 stringul returnat va fi
“0000000000001100 0000000011001000 0000000001111011 0000000000000001 0000001010111100” 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 5


uint16_t *create_array(unsigned int *size) {
    uint16_t *vector = NULL;
    *size = 0; 
    uint16_t element;
    while (scanf("%hu", &element) && *size < MAX_SIZE) {
        vector = realloc(vector, (*size + 1) * sizeof(uint16_t));
        if (vector == NULL) {
            perror("Eroare la alocarea dinamica!\n");
            exit(-1);
        }
        vector[*size] = element;
        (*size)++;
    }
    return vector;
}


char *arraytostr(uint16_t *array, int size) 
{
    int length = size * (16 + 1) - 1; //avem size numere si fiecare este pe 16 biti, mai adaugam unu pentru ca practic avem 17 biti cu spatiul gol si scadem 1 la final pentru ca avem numerotarea inceputa de la 0
    char *str = malloc((length + 1) * sizeof(char));
    if (str == NULL) {
        perror("Eroare la alocarea dinamica!\n"); 
        exit(-1);
    }

    char *ptr = str;
    for (int i = 0; i < size; i++) {
        for (int j = 15; j >= 0; j--) {
            if (array[i] & (1 << j)) {
                *ptr = '1';
            } else {
                *ptr = '0';
            }
            ptr++;
        }
        if (i < size - 1) {
            *ptr++ = ' '; 
        }
    }
    *ptr = '\0';
    return str;
}

int main(void) {
    uint16_t *array = NULL;
    char *str = NULL;
    unsigned int size = 0;

    printf("Introduceti numerele (maxim %d):\n", MAX_SIZE);
    array = create_array(&size);
    str = arraytostr(array, size);
    printf("%s\n", str);
    free(array);
    free(str);

    return 0;
}
