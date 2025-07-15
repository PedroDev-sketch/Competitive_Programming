#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no * esq, * dir;
}no;

no * minimo(no * r)
{
    if(r->esq == NULL) return r;
    return minimo(r->esq);
}