#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int prim(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    if(n == 2) {
        return 1;
    }

    for(int i = 3; i <= n/2; i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

//1 2 5 10 4 a
//0 1 2  3 4 pozitiile lui a 
//poz=1

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

void afisare(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void functie(int a[], int n) {
    for(int i = 0; i < n; i++) {
        if(prim(a[i]) == 1) {
            stergere_element(a, &n, i);
            i--;
        }
    }

    afisare(a, n);
}

//faci mereu cu Get-Content hexlines.txt | ./p

int main() {
    int a[MAX_SIZE];
    int i = 0;
    while(scanf("%d", &a[i]) != EOF && i < MAX_SIZE) {
        i++;
    }

    functie(a, i);
    return 0;
}