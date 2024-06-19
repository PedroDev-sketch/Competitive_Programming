#include <stdio.h>
#include <string.h>

void traduzir(int m, int n, char dicionario[m*2][80], char musica[n][80])
{
    for(int i = 0; i < n; i++)
    {
        char *palavra = strtok(musica[i], " ");
        while(palavra != NULL)
        {
            int encontrou = 0;
            for(int j = 0; j < m*2; j += 2)
            {
                if(strcmp(palavra, dicionario[j]) == 0)
                {
                    printf("%s ", dicionario[j+1]);
                    encontrou = 1;
                    break;
                }
            }
            if(!encontrou)
            {
                printf("%s ", palavra);
            }
            palavra = strtok(NULL, " ");
        }
        printf("\n");
    }
}

int main()
{
    int t, n, m;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d %d", &m, &n);
        char dicionario[m*2][80];
        char musica[n][80];

        for(int j = 0; j < m*2; j++)
        {
            scanf(" %[^\n]", dicionario[j]);
        }

        for(int j = 0; j < n; j++)
        {
            scanf(" %[^\n]", musica[j]);
        }

        traduzir(m, n, dicionario, musica);
    }

    return 0;
}