#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
} celula;

int desempilha(celula * p, int * y)
{
    celula * atual = p->prox;
    if(atual == NULL) return 0;

    *y = atual->dado;
    p->prox = atual->prox;
    free(atual);
    return 1;
}