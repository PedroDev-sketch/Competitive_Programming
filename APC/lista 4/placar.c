#include <stdio.h>

int main()
{
    int n, count = 0, nota = 0, menor = 0, flag;
    char nome[21], infeliz[21];
    while(scanf("%d", &n) != EOF)
    {
        count++;
        for(int i = 0; i < n; i++)
        {
            flag = 0;
            scanf("%s %d", nome, &nota);
            if(i == 0)
            {
                menor = nota;
                for(int j = 0; j < 21; j++)
                {
                    infeliz[j] = nome[j];
                }
            }
            else if(menor > nota)
            {
                menor = nota;
                for(int j = 0; j < 21; j++)
                {
                    infeliz[j] = nome[j];
                }
            }
            else if(menor == nota)
            {
                for(int j = 0; infeliz[j] != '\0' && nome[j]!='\0' && flag==0; j++)
                {
                    if(infeliz[j] > nome[j])
                    {
                        flag = 1;
                    }
                }
                if(flag)
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
        printf("%s", infeliz);
    }
    return 0;
}