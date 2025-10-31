#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct link
{
    int dados;
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
    b->cor = a->cor;
    a->cor = RED;
    return b;
}

link * rot_esq(link* a)
{
    link* b = a->dir;
    link* beta = b->esq;
    b->esq = a;
    a->dir = beta;
    b->cor = a->cor;
    a->cor = RED;
    return b;
}

void sobe_cor(link* a)
{
    a->esq->cor = a->dir->cor = BLACK;
    a->cor = RED;
}

link* insere(link* raiz, int x)
{
    if(raiz != NULL)
    {
        if(x < raiz->dados) raiz->esq = insere(raiz->esq, x);
        if(x > raiz->dados) raiz->dir = insere(raiz->dir, x);

        if(!ehVerm(raiz->esq) && ehVerm(raiz->dir))
            raiz = rot_esq(raiz);
        if(ehVerm(raiz->esq) && ehVerm(raiz->esq->esq))
            raiz = rot_dir(raiz);
        if(ehVerm(raiz->esq) && ehVerm(raiz->dir))
            sobre_cor(raiz);
        return raiz;
    }
    else
    {
        link* novo = malloc(sizeof(link));
        novo->dados=x;
        novo->cor=RED;
        novo->esq=novo->dir=NULL;
        return novo;
    }
}

link* insere_abb_rne(link* raiz, int x)
{
    raiz = insere(NULL, x);
    raiz->cor = BLACK;
    return raiz;
}