#include <stdio.h>

int contarEstrelas(int qtd, int abertura)
{
    int estrela, num = 0;
    for(int i = 0; i < qtd; i++)
    {
        scanf("%d", &estrela);
        if(estrela * abertura >= 40000000)
        {
            num++;
        }
    }
    return num;
}