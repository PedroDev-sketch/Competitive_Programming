#include <stdio.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int a = 100;
    int b = 150;
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}