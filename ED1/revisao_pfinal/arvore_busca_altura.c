#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
}no;

int altura(no *r)
{
    if(r == NULL) return 0;

    int alt_dir = altura(r->dir)+1;
    int alt_esq = altura(r->esq)+1;

    if(alt_dir > alt_esq) return alt_dir;
    return alt_esq;
}