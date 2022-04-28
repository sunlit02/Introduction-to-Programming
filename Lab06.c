#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 10000

int isort(int v[], int n);
void copyarray(int a[], int b[], int n);
void printarray(int a[], int n);

int main()
{
    int numbers[ARRAYSIZE], data[ARRAYSIZE];
    int i, n count;

    for (i = 0; i < ARRAYSIZE; i++)
        numbers[i] = rand();
    printf("Before sort (the first 8 numbers) : ");
    printarray(numbers, 8);
    printf("\n");

    for (n = 10; n<= ARRAYSIZE; n*=10)
    {
        copyarray(data, numbers, n);
        count = isort(data, n);
        printf("After insertion sort (the first 5 numbers) : ");
        printarray(data, 5);
        printf("The number of swaps in insertion sort : %d\n\n", count);
    }
}


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

void copyarray(int a[], int b[], int n) //b의 원소 n개를 a로 옳김
{
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++))
    {
        printf("%d ", a[i])
    }
}
