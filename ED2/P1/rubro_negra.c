#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct link
{
    int dado;
    int cor;
    struct link *esq, * dir;
}link;

int ehVerm(link* a)
{
    return a->cor==RED;
}

link* rotacao_dir(link* a)
{
    link* b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    b->cor = a->cor;
    a->cor = RED;
    return b;
}

link* rotacao_esq(link * a)
{
    link* b = a->dir;
    link* beta = b->esq;
    b->esq = a;
    a->dir = beta;
    b->cor=a->cor;
    a->cor=RED;
    return b;
}

void sobe_cor(link* raiz)
{
    raiz->cor = RED;
    raiz->esq = raiz->dir = BLACK;
}

link* insere(link *raiz, int x)
{
    if(raiz != NULL)
    {
        if(x<raiz->dado) raiz->esq = insere(raiz->esq, x);
        if(x>raiz->dado) raiz->dir = insere(raiz->dir, x);

        if(!ehVerm(raiz->esq) && ehVerm(raiz->dir))
            raiz = rotacao_esq(raiz);
        if(ehVerm(raiz->esq) && ehVerm(raiz->esq->esq))
            raiz = rotacao_dir(raiz);
        if(ehVerm(raiz->esq) && ehVerm(raiz->dir))
            sobe_cor(raiz);
        return raiz;
    }
    else
    {
        link* novo = malloc(sizeof(link));
        novo->dado = x;
        novo->cor = RED;
        novo->esq = novo->dir = NULL;
        return novo;
    }
}

link* insere_abb_rne(link* raiz, int x)
{
    raiz = insere(raiz, x);
    raiz->cor = BLACK;
    return raiz;
}