#include <stdio.h>
#include <stdlib.h>

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
    pilha * f = malloc(sizeof(pilha));
    f->prox = NULL;
    return f;
}

void empilha(pilha * f, no * x)
{
    pilha * novo = malloc(sizeof(pilha));

    novo->dado = x;
    novo->prox = f->prox;
    f->prox = novo;
}

no * desempilha(pilha * f)
{
    if(f->prox == NULL) return NULL;
    pilha * lixo = f->prox;

    no * x = lixo->dado;
    f->prox = lixo->prox;

    free(lixo);
    return x;
}

void destroi_pilha(pilha * f)
{
    pilha * atual = f->prox;
    while(atual != NULL)
    {
        pilha * lixo = atual;
        atual = atual->prox;
        free(lixo);
    }
}

void pos_ordem(no * raiz)
{
    if(raiz == NULL) return;

    pilha * f = cria_pilha();
    pilha * p = cria_pilha();
    empilha(f, raiz);

    no * r = raiz;
    while(f->prox != NULL)
    {
        r = desempilha(f);
        empilha(p, r);

        if(r->esq != NULL) empilha(f, r->esq);
        if(r->dir != NULL) empilha(f, r->dir);
    }
    
    while(p->prox != NULL)
    {
        r = desempilha(p);
        printf("%d ", r->dado);
    }

    printf("\n");
    destroi_pilha(f);
    destroi_pilha(p);
    free(f);
    free(p);
}