#include <stdio.h>

int main()
{
    int n, count = 0, nota = 0, menor = 0;
    char nome[21], infeliz[21];
    while(scanf("%d", &n) != EOF)
    {
        count++;
        for(int i = 0; i < n; i++)
        {
            scanf("%s %d", nome, &nota);
            if(i == 0)
            {
                menor = nota;
                for(int j = 0; j < 21; j++)
                {
                    infeliz[j] = nome[j];
                }
            }
            else if(nota < menor)
            {
                menor = nota;
                for(int j = 0; j < 21; j++)
                {
                    infeliz[j] = nome[j];
                }
            }
            else if(nota == menor)
            {
                int j;
                for(j = 0; infeliz[j] != '\0' && nome[j]!='\0'; j++)
                {
                    if(infeliz[j] < nome[j])
                    {
                        for(int k = 0; k < 21; k++)
                        {
                            infeliz[k] = nome[k];
                        }
                        break;
                    }
                    else if(infeliz[j] > nome[j])
                    {
                        break;
                    }
                }
                if(infeliz[j] == '\0' && nome[j]!='\0')
                {
                    for(int k = 0; k < 21; k++)
                    {
                        infeliz[k] = nome[k];
                    }
                }
            }
        }
        printf("\n");
        printf("Instancia %d\n", count);
        printf("%s\n", infeliz);
    }
    return 0;
}
