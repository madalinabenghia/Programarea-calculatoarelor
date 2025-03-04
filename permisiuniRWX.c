#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void permisiuni_functie(uint8_t n, char *permisiuni) {
    char rwx[3] = {'r', 'w', 'x'};
    for(int i = 0; i < 6; i++) {
        if(n & (1 << (5 - i))) {
            permisiuni[i] = rwx[i % 3];
        }
        else {
            permisiuni[i] = '-';
        }
    }
    permisiuni[6] = '\0';
}

void showBits(unsigned a, uint8_t *permisiuni){
    int i;
    for(i = 0; i < a; i++) {
        char permisiuni_nou[7];
        permisiuni_functie(permisiuni[i], permisiuni_nou);
        printf("%s\n", permisiuni_nou);
    }
}

void modificare_permisiuni(uint8_t *permisiuni, int n, uint8_t mask) {
    for(int i = 0; i < n; i++) {
        permisiuni[i] = permisiuni[i] | (uint8_t) mask ;
    }
}

int main() {
    uint8_t permisiuni[100];
    int n;
    uint8_t mask;

    scanf("%d", &n);
    scanf("%hhu", &mask);

    for(int i = 0; i < n; i++) {
        scanf("%hhu", &permisiuni[i]);
    }

    modificare_permisiuni(permisiuni, n, mask);
    showBits(n, permisiuni);
    return 0;

}