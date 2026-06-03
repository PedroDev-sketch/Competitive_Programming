#include <stdio.h>

int encaixa(int a, int b)
{
    int casa = 10;
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

/* int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", encaixa(a, b));

    return 0;
} */