#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
}celula;

celula * busca(celula * le, int x)
{
    if(le->prox == NULL) return le;
    celula * atual = le->prox;

    while(atual != NULL && atual->dado != x)
    {
        atual = atual->prox;
    }

    return atual;
}

celula * busca_rec(celula * le, int x)
{
    celula * atual = le->prox;

    if(atual == NULL) return NULL;
    else if(atual->dado == x) return atual;

    return busca_rec(atual, x);
}