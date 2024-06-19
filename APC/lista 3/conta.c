#include <stdio.h>

int main()
{
    int n, conta = 0;
    scanf("%d", &n);
    if(n <= 10)
    {
        conta = 7;
    }
    else if(n <= 30)
    {
        conta = 7 + (n - 10);
    }
    else if(n <= 100)
    {
        conta = 7 + 20 + (n - 30) * 2;
    }
    else if(n > 100)
    {
        conta = 7 + 20 + 140 + (n - 100) * 5;
    }
    printf("%d", conta);
    return 0;
}