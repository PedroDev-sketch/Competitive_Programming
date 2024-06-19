#include <stdio.h>

int main()
{
    int n, m, soma = 0, comp;
    scanf("%d %d", &n, &m);
    int bairro[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &bairro[i][j]);
        }
    }
    for(int i = 0; i < m; i++)
    {
        comp = 0;
        if(i == 0)
        {
            for(int j = 0; j < n; j++)
            {
                soma += bairro[j][i];
            }
        }
        else 
        {
            for(int j = 0; j < n; j++)
            {
                comp += bairro[j][i];
            }
        }
        if(soma > comp && i != 0) soma = comp;
    }
    printf("%d\n", soma);
    return 0;
}