#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
}celula;

int desenfileira(celula * f, int * y)
{
    celula * atual = f->prox;
    if(atual == NULL) return 0;

    *y = atual->dado;
    f->prox = atual->prox;
    free(atual);
    return 1;
}