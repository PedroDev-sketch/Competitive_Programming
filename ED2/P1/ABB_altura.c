#include <stdio.h>

typedef struct no
{
    int chave;
    struct no * esq, * dir;
}no;

int altura(no * r)
{
    if(r==NULL)
     return 0;
    
    int altdir = altura(r->dir)+1;
    int altesq = altura(r->esq)+1;
    if(altdir > altesq)
        return altdir;
    else
        return altesq; 
}