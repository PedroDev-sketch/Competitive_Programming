#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) 
{
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL) return NULL;
    nova->prox = f->prox;

    if(f==NULL) return NULL;
    f->dado = x;
    f->prox = nova;
    return nova;
}