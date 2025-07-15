#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no * esq, * dir;
}no;

no * maximo(no * r)
{
    if(r->dir != NULL)
    {
        return maximo(r->dir);
    } else return r;
}