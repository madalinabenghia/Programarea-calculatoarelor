#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *add_big_numbers_binary(char *nr1, char *nr2) {
    int len1 = strlen(nr1);
    int len2 = strlen(nr2);
    int dim_max;

    if(len1 > len2) {
        dim_max = len1;
    }
    else {
        dim_max = len2;
    }
    char *nr3 = (char*)malloc(dim_max + 2);
    nr3[dim_max + 2] = '\0';

    int i, j, k = dim_max, carry = 0;
    for(i = len1 - 1, j = len2 - 1; k >= 0; i--, j--, k--) {
        int bit1, bit2;
        if(i >= 0) {
            bit1 = nr1[i] - '0';
        }
        else {
            bit1 = 0;
        }

        if(j >= 0) {
            bit2 = nr2[j] - '0';
        }
        else {
            bit2 = 0;
        }

        int s = bit1 + bit2 + carry;
        if(s % 2 == 0) {
            nr3[k] = '0';
        }
        else {
            nr3[k] = '1';
        }

        if(s >= 2) {
            carry = 1;
        }
        else {
            carry = 0;
        }
    }

     if(carry == 1) {
            nr3[0] = '1';
            return nr3; 
        }

        return nr3 + 1;
}

int main() {
    char nr1[1001], nr2[1001];
    scanf("%s", nr1);
    scanf("%s", nr2);

    char *suma = add_big_numbers_binary(nr1, nr2);
    printf("%s", suma);
    if(suma[0] == '1') {
        free(suma);
    }
    else {
        free(suma - 1);
    }
    return 0;
}