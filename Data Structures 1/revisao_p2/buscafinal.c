#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
}celula;

celula * busca(celula * le, int x)
{
    celula * atual = le->prox;

    while(atual != NULL)
    {
        if(atual->dado == x) return atual;
        atual = atual->prox;
    }
    return NULL;
}

celula * busca_rec(celula * le, int x)
{
    celula * atual = le->prox;

    if(atual == NULL) return NULL;
    if(atual->dado == x) return atual;
    return busca_rec(atual, x);
}
