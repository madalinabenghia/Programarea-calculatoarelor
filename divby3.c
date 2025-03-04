#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int DivBy3(int n) {
    if(n % 3 == 0) {
        return 1;
    }

    return 0;
}

void afisare(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void stergere_element(int *a, int *n, int poz) {
    for(int i = 0; i < *n; i++) {
        if(a[i] == a[poz]) {
            for(int j = i + 1; j < *n; j++) {
                a[i] = a[j];
            }
            (*n)--;
        }
    }
}
//1 3 6 9
//1 6 9
void functie(int a[], int n) {
    for(int i = 0; i < n; i++) {
        if(DivBy3(a[i]) == 1) {
            stergere_element(a, &n, i);
            i--;
        }
    }
    afisare(a, n);

}

int main() {
    int a[MAX_SIZE];
    int i = 0;
    while(scanf("%d", &a[i]) != EOF && i < MAX_SIZE) {
        i++;
    }

    functie(a, i);
    return 0;
}