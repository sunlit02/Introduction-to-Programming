#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 10000


int isort(int v[], int n)
{
    int i, j, temp;

    for (i = 1; i < n; i++)  //step 1, 2, 3, ... 의 비교할 수  
    {
        for (j=i-1; j >= 0 && v[j] > v [j+1]; j--)  //step n-1 단계
        {
            temp = v[j], v[j]=v[j+1], v[j+1] = temp;  // 앞의 수들과 비교
        }
    }
}

