#include <stdio.h>

int ret = 0;

int roll(int n)
{
    if(n == 0) return 0;
    else 
    {
        ret += n;
        n--;
        return roll(n);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    roll(n);
    printf("%d", ret);
}