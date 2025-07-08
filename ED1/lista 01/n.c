#include <stdio.h>

int encaixa(int a, int b)
{
    int casa = 1;
    int ans = 0;

    while(1)
    {
        if(a % casa == b)
        {
            ans = 1;
            break;
        }
        else casa *= 10;

        if(casa > b *100) break;
    }

    return ans;
}

int segmento(int a, int b)
{
    int ans = 0;
    if(a == b) ans = 1;
    
    if(a > b)
    {
        while(a > 0)
        {
            if(encaixa(a, b))
            {
                ans = 1;
                break;
            }
            else a /= 10;
        }
    }
    else
    {
        while(b > 0)
        {
            if(encaixa(b, a))
            {
                ans = 1;
                break;
            }
            else b /= 10;
        }
    }

    return ans;
}

/* int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", segmento(a, b));

    return 0;
}   */