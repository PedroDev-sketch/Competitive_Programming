#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct link
{
    int dado;
    int cor;
    struct link *esq, *dir;
}link;

int ehVerm(link* r)
{
    return r->cor==RED;
}

link* rot_dir(link* a)
{
    link* b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    b->cor=a->cor;
    a->cor = RED;
    return b;
}

link* rot_esq(link* a)
{
    link* b = a->dir;
    link* beta = b->esq;
    b->esq=a;
    a->dir = beta;
    b->cor=a->cor;
    a->cor = RED;
    return b;
}

void sobe_cor(link* r)
{
    r->esq->cor = r->dir->cor = BLACK;
    r->cor = RED;
}

link* insere(link* r, int x)
{
    if(r!=NULL)
    {
        if(r->dado > x) r->esq = insere(r->esq, x);
        if(r->dado < x) r->dir = insere(r->dir, x);

        if(!ehVerm(r->esq) && ehVerm(r->dir))
            //rot esq
        if(ehVerm(r->esq) && (ehVerm(r->esq->esq)))
            //rot dir
        if(ehVerm(r->esq) && ehVerm(r->dir))
            //sobe cor

        return r;
    }
    else
    {
        link* novo = malloc(sizeof(link));
        novo->dado = x;
        novo->cor = RED;
        novo->dir=novo->esq=NULL;
        return novo;
    }
}