#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula * prox;
}celula;

void imprime(celula * le)
{
    celula * atual = le;
    while(atual->prox != NULL)
    {
        atual = atual->prox;
        printf("%d -> ", atual->dado);
    }
    printf("NULL\n");
}

void imprime_rec(celula * le)
{
    celula * atual = le->prox;
    if(atual == NULL) {printf("NULL\n"); return;}
    else printf("%d -> ", atual->dado);

    imprime_rec(atual);
}

/* int main()
{
    celula * le = malloc(sizeof(celula));
    celula * dois = malloc(sizeof(celula));
    celula * tres = malloc(sizeof(celula));
    celula * quatro = malloc(sizeof(celula));

    le->prox = dois;
    dois -> prox = tres;
    tres->prox = quatro;
    quatro ->prox = NULL;

    dois->dado = 1;
    tres->dado = 2;
    quatro->dado = 3;

    imprime(le);
    imprime_rec(le);

    return 0;
} */