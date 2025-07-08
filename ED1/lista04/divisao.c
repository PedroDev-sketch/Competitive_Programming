#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
} celula;

void divide_lista(celula *l, celula * l1, celula * l2)
{
    celula * atual = l->prox;
    while(atual != NULL)
    {
        if(atual->dado % 2)
        {
            l1->prox = atual;
            l1 = l1->prox;
        }
        else
        {
            l2->prox = atual;
            l2 = l2->prox;
        }
        atual = atual->prox;
    }
    l1->prox = NULL;
    l2->prox = NULL;
}