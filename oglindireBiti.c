#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool oglindeste_biti(uint32_t num) {
    uint32_t reversed = 0;
    uint32_t original = num;
    int nr = sizeof(num) * 8;

    for (int i = 0; i < nr; i++) {
        reversed |= ((num >> i) & 1) << (nr - 1 - i); // Mutăm fiecare bit
    }
    printf("%u %u", original, reversed);
    return original == reversed;
}

int main() {
    uint32_t nr;
    scanf("%u", &nr);
    if(oglindeste_biti(nr)) {
        printf("Da\n");
    }
    else {
        printf("Nu\n");
    }
    return 0;
}