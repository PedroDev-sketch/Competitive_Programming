#include <stdio.h>

int main()
{
    int f, l, convert, inNum;
    scanf("%d %d", &f, &l);
    char inC;
    char mapa[f][l];

    for(int i = 0; i < f; i++)
    {
        for(int j = 0; j < l; j++)
        {
            mapa[i][j] = 0;
        }
    }

    while(scanf(" %c%d", &inC, &inNum) != EOF)
    {
        convert = inC;
        mapa[convert - 65][inNum - 1] = 1;
    }

    printf("  ");

    for(int i = 1; i <= l; i++)
    {
        if(i < 10) printf("0%d ", i);
        else printf("%d ", i);
    }

    printf("\n");

    for(int i = f-1; i >= 0; i--)
    {
        printf("%c ", i+65);
        for(int j = 0; j < l; j++)
        {
            if(mapa[i][j] == 1) printf("XX ");
            else printf("-- ");
        }
        printf("\n");
    }
    return 0;
}