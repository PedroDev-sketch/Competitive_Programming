#include <stdio.h>

typedef struct no
{
    int dado;
    struct no * esq, * dir;
}no;

typedef struct pilha
{
    no * dado;
    struct pilha * prox;
}pilha;

pilha * cria_pilha()
{
    pilha * p = malloc(sizeof(pilha));
    p->prox=NULL;
    return p;
}

void push(pilha * p, no * val)
{
    pilha * novo = malloc(sizeof(pilha));
    novo->dado = val;
    novo->prox = p->prox;
    p->prox = novo;
}

no * pop(pilha * p)
{
    if(p->prox==NULL)return NULL;
    no * atual = p->prox->dado;
    pilha * lixo = p->prox;
    p->prox = lixo->prox;
    free(lixo);
    return atual;
}

no * top(pilha *p)
{
    if(p->prox == NULL) return NULL;
    return p->prox->dado;
}

void clear(pilha * p)
{
    while(p!=NULL)
    {
        pilha * lixo = p;
        p = p->prox;
        free(lixo);
    }
}

void em_ordem(no * raiz)
{
    if(raiz == NULL) return;
    no * r = raiz;

    pilha * p = cria_pilha();
    while(top(p)!=NULL || r!=NULL)
    {
        while(r != NULL)
        {
            push(p, r);
            r = r->esq;
        }
        if(top(p) != NULL)
        {
            r = pop(p);
            printf("%d ", r->dado);
            r = r->dir;
        }

    } 
    printf("\n");

    clear(p);
}