#include <ctype.h>
#include <stdio.h>
#define SIZE 100

int gethex(int *pn)
{
    int c, sign;

    while (isspace ( c = getchar()));  // 공백 지나가기

    if (! isdigit(c) && c!= EOF && c!= '+' && c != '-')
    {
        ungetc(c, stdin);  // 숫자나 부호가 아닐 때
        return 0;
    } 

    sign = (c == '-') ? -1 : 1;   // 부호 확인
    if (c == '+' || c == '-')
        c = getchar();     // 부호 넘기기

    for (*pn = 0; isdigit(c) || isalpha(c); c = getchar())   // 숫자 인식
    {
        if (isdigit(c) != 0)  *pn = 16* *pn + (c - '0');
        else if (isalpha(c) == 1)   *pn = 16* *pn + (c - 'A')+10;
        else if (isalpha(c) == 2)   *pn = 16* *pn + (c - 'a')+10;
    }

    *pn *= sign;    // 부호 계산

    if (c != EOF)     // 끝이 아닐 경우, 오류
        ungetc(c, stdin);

    return c;
}
int main()
{
    int array[SIZE], n;
    int gethex(int *);
    int i, sum;

    for (n = 0; n<SIZE && gethex(&array[n]) != EOF; n++); // array[n]의 주소값을 *pn에 할당  -> *pn = &array[n]

    sum = 0;
    for (i = 0; i < n; i++)
        sum += array[i];

    printf("The sum is %d\n", sum);
}