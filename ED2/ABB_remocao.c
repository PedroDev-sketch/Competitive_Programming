#include <stdio.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
}no;

no * remover(no *r, int x)
{
    if(r==NULL) return NULL;
    if(r->chave < x);
}