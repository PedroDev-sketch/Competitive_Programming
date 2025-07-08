#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
}celula;

int empilha(celula * p, int x)
{
    celula * pilha = malloc(sizeof(celula));
    if(pilha == NULL || p == NULL) return 0;
    pilha->dado = x;

    pilha->prox = p->prox;
    p->prox = pilha;
    return 1;
}