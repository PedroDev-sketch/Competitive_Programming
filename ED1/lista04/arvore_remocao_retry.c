#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no * esq, * dir;
}no;

void remove_antecessor(no * r)
{
    no * pai = r;
    no * filho = r->esq;

    while(filho->dir != NULL)
    {
        pai = filho;
        filho = filho->dir;
    }

    r->chave = filho->chave;

    if(pai != r) pai->dir = filho->esq;
    else pai->esq = filho->esq;
    free(filho);
}

no * remover(no * r, int x)
{
    if(r == NULL) return NULL;
    else if(r->chave > x) r->esq = remover(r->esq, x);
    else if(r->chave < x) r->dir = remover(r->dir, x);
    else
    {
        if(r->esq == NULL)
        {
            no * ret = r->dir;
            free(r);
            return ret;
        }
        else if(r->dir == NULL)
        {
            no * ret = r->esq;
            free(r);
            return ret;
        }
        else
        {
            remove_antecessor(r);
        }
    }
    return r;
}