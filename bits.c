#include <stdio.h>
#include <string.h>

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n))&~(~0<<n);
}
void printbinary(unsigned x)
{
    int i;

    for (i = 0; i<32; i++)
    {
        putchar(x & 0x80000000 ? '1':'0');
        if (i%4 == 3)
            putchar(' ');
            x <<= 1;
    }
}
int main()
{
    int p = 20, n=6;
    int x = 0xABCDEF39;
    printf("x: \t\t\t");
    printbinary(x);
    printf("~((~0>>n << p): \t");
    printbinary(~((0>>n)<<p));
}