#include <stdio.h>
#include <string.h>

typedef struct dicionario
{
    char palavra[81];
    char trad[81];
} dicio;

void traduzir(int m, int n, dicio aqui[m])
{
    for(int i = 0; i < n; i++)
    {
        char comp[81];
        int flag = 0;
        while(scanf("%80s", comp) == 1)
        {
            for(int j = 0; j < m; j++)
            {
                if(strcmp(comp, aqui[j].palavra) == 0)
                {
                    printf("%s ", aqui[j].trad);
                    flag = 1;
                    break;
                }
            }
            if(!flag) printf("%s ", comp);
            flag = 0;
            if(getchar() == '\n') break;
        }
        printf("\n");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int m, n;
        char letra[81];
        scanf("%d %d", &m, &n);
        dicio aqui[m];

        for(int i = 0; i < m; i++)
        {
            scanf(" %80s", aqui[i].palavra);
            scanf(" %[^\n]", aqui[i].trad);
        }

        traduzir(m, n, aqui);
    }
    return 0;
}