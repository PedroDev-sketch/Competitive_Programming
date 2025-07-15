#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct fila
{
    int * dados;
    int N, p, u;
}fila;

int enfileira(fila * f, int x)
{
    if((f->u + 1) % f->N == f->p)
    {
        int new_N = 2*f->N;
        f->dados = realloc(f->dados, new_N * sizeof(int));
        if(f->dados == NULL) return 0;

        if(f->u < f->p)
        {
            int block1_size = f->u, block2_size = f->N - f->p;

            if(block1_size < block2_size)
            {
                memmove(&f->dados[new_N - f->N], &f->dados[0], block1_size * sizeof(int));
                f->u = f->N + block1_size;
            }
            else
            { 
                memmove(&f->dados[new_N - block2_size], &f->dados[f->p], block2_size * sizeof(int)); 
                f->p = new_N - block2_size;
            }
        }

        f->N = new_N;
    }
    
    f->dados[f->u] = x;
    f->u = (f->u+1) % f->N;
    

    return 1;
}