#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
}no;

no * inserir(no * r, int x)
{
    if(r->chave > x) r->esq = inserir(r->esq, x);
    else if(r->chave < x) r->dir = inserir(r->dir, x);

    if(r == NULL)
    {
        no * novo = malloc(sizeof(no));
        novo->chave = x;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }

    return r;
}