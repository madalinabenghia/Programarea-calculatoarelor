#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

uint64_t resetbits(uint64_t x, uint8_t p, uint8_t n) {
    if(p >= 64 || n == 0 || p + n > 64) {
        return 0;
    }

    uint64_t mask = ((1 << n) - 1) << p;

    return x & ~mask;
}

void print_bit_64 (uint64_t nr)
{
  uint64_t mask = 0x80000000; // 0b1000000000000000
  uint32_t i = 0;
  for (i = 0; i < 64; i++)
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
    uint64_t x;
    uint8_t n, p;
    scanf("%llu", &x);
    scanf("%hhu", &p);
    scanf("%hhu", &n);

    print_bit_64(x);

    uint64_t rez = resetbits(x, p, n);
    print_bit_64(rez);
    return 0;
}