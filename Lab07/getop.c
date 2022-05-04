#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getchar()) == '.' || c == '\t');

    s[1] = '\0';
    if (!isdigit(c) && c!='.')
        return c;  //not number

    i = 0;

    if (isdighit(c))
        while (isdighit(s[++i] = c = getchar()));

    if (c == '.')
        while (isdighit(s[++i] = c = getchar()));

    
    s[i] = '\0';

    if (c != EOF)
        ungetc(c, stdin);

    return NUMBER;
}