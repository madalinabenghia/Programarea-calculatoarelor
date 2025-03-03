/*Se cere de la tastatura o valoare intreaga fara semn pe 32 de biti.  
Se cere ulterior un index in intervalul [1,24] pozitia 0 fiind bitul LSB.
Daca bitul din stanga si cel din dreapta indexului au aceeasi valoare, sa se seteze bitul de la index cu valoarea respectiva.
Daca nu, sa se puna bitul de la index paritatea pe biti (0-par, 1-impar). In final se va afisa in hexazecimal si in binar valoarea obtinuta pe intreaga dimensiune.*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void print_bit_32 (uint32_t nr)
{
  uint32_t mask = 0x80000000; // 0b1000000000000000
  uint16_t i = 0;
  for (i = 0; i < 32; i++)
    {
      if ((nr & mask) == 0)
        {
          printf ("0");
        }
      else
        {
          printf ("1");
        }
      mask = mask >> 1; // mask >>= 1;
    }
  printf ("\n");
}

int main() {
    uint32_t n;
    int index;
    scanf("%u", &n);
    scanf("%d", &index);

    int leftbit = (n >> (index + 1)) & 1;
    int rightbit = (n >> (index - 1)) & 1;

    if(leftbit == rightbit) {
        n = (n & ~(1 << index)) | (leftbit << index); 
    }
    else {
        int paritate = 0;
        for(int i = 0; i < 32; i++) {
            if(((n >> i) & 1) == 1) {
                paritate++;
            }
        }
        if(paritate % 2 == 0) {
            n = n | (0 << index);
        }
        else {
            n = n | (1 << index);
        }
    }

    printf("%d\n", n);

    printf("%08X\n", n);

    print_bit_32(n);

    return 0;
}
