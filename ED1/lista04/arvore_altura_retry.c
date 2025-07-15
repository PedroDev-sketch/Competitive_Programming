#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
}no;

int altura(no * r)
{
    if(r==NULL) return 0;

    int e = altura(r->esq) + 1;
    int d = altura(r->dir) + 1;
    if(e>=d) return e;
    else return d;
}