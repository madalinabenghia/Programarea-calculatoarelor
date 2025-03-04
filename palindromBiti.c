#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 5 

uint8_t oglindeste_biti(uint8_t num) {
    uint8_t reversed = 0;

    for (int i = 0; i < 8; i++) {
        reversed |= ((num >> i) & 1) << (7 - i); 
    }

    return reversed;
}

void afisare_biti(uint8_t nr) {
    uint8_t mask = 0x80; // 0b10000000
    for (int i = 0; i < 8; i++) {
        printf("%d", (nr & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");
}

void afisare_biti_palindrom(uint16_t nr) {
    uint16_t mask = 0x8000; // 0b1000000000000000
    for (int i = 0; i < 16; i++) {
        printf("%d", (nr & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");
}

void functie(uint8_t input[], uint16_t output[], int n) {
    for (int i = 0; i < n; i++) {
        uint8_t num = input[i];
        uint8_t oglindit = oglindeste_biti(num);
        output[i] = (oglindit << 8) | num; 

        printf("Numar initial: %d ", num);
        afisare_biti(num);
        printf("\n");

        printf("Palindrom: %d ", output[i]);
        afisare_biti_palindrom(output[i]);
        printf("\n\n");
    }
}

int main() {
    uint8_t input[MAX_SIZE];  
    uint16_t output[MAX_SIZE]; 
    int i= 0;

    printf("Introduceti numere pe 8 biti %d:\n", MAX_SIZE);
    while (i < MAX_SIZE && scanf("%hhu", &input[i]) == 1) {
        i++;
    }

    printf("\nRezultatele procesarii:\n");
    functie(input, output, i);

    return 0;
}