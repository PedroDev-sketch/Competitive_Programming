#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no * esq, * dir;
}no;

int altura(no * r)
{
    if(r==NULL) return 0;

    int altura_esq = altura(r->esq);
    int altura_dir = altura(r->dir);

    if(altura_esq > altura_dir)
        return 1 + altura_esq;
    else    
        return 1 + altura_dir;
}
