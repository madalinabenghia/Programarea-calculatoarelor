#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 6  

char *fib_str() {
    int fib[N];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    
    for (int i = 3; i < N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    char *result = (char *)malloc(N * 10);
    if (!result) {
        return NULL;
    }
    
    char *ptr = result;
    for (int i = 0; i < N; i++) {
        int len = sprintf(ptr, "%d ", fib[i]);
        ptr += len;
    }
    
    return result;
}

int main() {
    char *fib_sequence = fib_str();
    if (fib_sequence) {
        printf("%s\n", fib_sequence);
        free(fib_sequence);
    }
    return 0;
}