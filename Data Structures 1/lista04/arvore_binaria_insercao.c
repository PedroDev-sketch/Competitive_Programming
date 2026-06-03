#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no * esq, * dir;
}no;

no * inserir(no * r, int x)
{
    if(r != NULL)
    {
        if(x < r->chave) r->esq = inserir(r->esq, x);
        else if(x > r->chave) r->dir = inserir(r->dir, x);
        return r;
    }
    else
    {
        no * novo = malloc(sizeof(novo));
        novo->esq = novo->dir = NULL;
        novo->chave = x;
        return novo;
    }
}