#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
}celula;

void insere_inicio(celula * le, int x)
{
    celula * nova = malloc(sizeof(celula));
    nova -> dado = x;
    nova->prox = le->prox;

    le->prox=nova;
}

void insere_antes(celula * le, int x, int y)
{
    celula * atual = le;
    while(atual->prox != NULL && atual->prox->dado != y)
    {
        atual = atual->prox;
    }

    insere_inicio(atual, x);
}