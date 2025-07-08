#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x)
{
    if (f->N == 0) {
        f->N = 2;
        f->dados = malloc(f->N * sizeof(int));
        if (f->dados == NULL) return 0;
        f->p = 0;
        f->u = 0;
    }

    if ((f->u + 1) % f->N == f->p)
    {
        int N_antigo = f->N;
        int novo_N = f->N * 2;
        f->dados = realloc(f->dados, novo_N * sizeof(int));
        if (f->dados == NULL) return 0;
        f->N = novo_N;

        if (f->p > f->u)
        {
            // Caso 1 (TESTE 2): Fila contígua, mas com "wrap-around" (u=0).
            // Apenas corrigir o ponteiro 'u'.
            if (f->u == 0) {
                f->u = N_antigo;
            } 
            // Caso 2 (TESTE 1): Fila fisicamente dividida.
            // Mover o bloco de 'p' para o final do novo vetor.
            else {
                int tam_bloco_p = N_antigo - f->p;
                int novo_p = novo_N - tam_bloco_p;
                memmove(&f->dados[novo_p], &f->dados[f->p], tam_bloco_p * sizeof(int));
                f->p = novo_p;
            }
        }
    }

    f->dados[f->u] = x;
    f->u = (f->u + 1) % f->N;

    return 1;
}