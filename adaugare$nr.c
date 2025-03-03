/*Un sir de caractere care se sfarsea cu “.”. 
Trebuia  sa adaugam “$” in fata fiecarui numar (nu cifra). Spre ex: 123Ana are mere si 23pere. sa devina $123Ana are mere si $23pere.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void functie(char str[]) {
    char rez[1024] = "";
    char buffer[64];

    for(int i = 0; i < strlen(str); i++) {
        if(isdigit(str[i]) && isdigit(str[i + 1])) {
            strcat(rez, "$");
        }

        buffer[0] = str[i];
        buffer[1] = '\0';
        strcat(rez, buffer);
    }
    printf("%s", rez);
}

int main() {

    char sir[1024];

    fgets(sir, sizeof(sir), stdin);

    functie(sir);

    return 0;
}
//scanf - doar caractere
//fgets - siruri