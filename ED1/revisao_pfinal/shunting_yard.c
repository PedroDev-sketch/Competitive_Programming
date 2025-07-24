#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct fila
{
    char dado;
    struct fila * prox;
}fila;

fila * cria_fila()
{
    fila * f = malloc(sizeof(fila));
    f->prox = f;
    return f;
}

fila * enfileira(fila * f, char x)
{
    fila * novo = malloc(sizeof(fila));
    f->dado = x;
    novo->prox = f->prox;
    f->prox = novo;
    return novo;
}

int desenfileira(fila * f, char * x)
{
    if(f->prox == f) return 0;

    fila * lixo = f->prox;
    *x = lixo->dado;

    f->prox = lixo->prox;
    free(lixo);
    return 1;
}

void destroi_fila(fila * f)
{
    fila * atual = f->prox;
    while(atual != f)
    {
        fila * lixo = atual;
        atual = atual->prox;
        free(lixo);
    }
}

typedef struct pilha
{
    char chave;
    struct pilha * prox;
}pilha;

pilha * cria_pilha()
{
    pilha * p = malloc(sizeof(pilha));
    p->prox = NULL;
    return p;
}

void empilha(pilha * p, char x)
{
    pilha * novo = malloc(sizeof(pilha));

    novo->prox = p->prox;
    novo->chave = x;

    p->prox = novo;
}

int desempilha(pilha * p, char * x)
{
    if(p->prox == NULL) return 0;

    pilha * lixo = p->prox;
    *x = lixo->chave;

    p->prox = lixo->prox;
    free(lixo);
    return 1;
}

void destroi_pilha(pilha * p)
{
    pilha * atual = p->prox;
    while(atual != NULL)
    {
        pilha * lixo = atual;
        atual = atual->prox;
        free(lixo);
    }
}

char topo(pilha * p)
{
    if(p->prox == NULL) return ' ';
    else return p->prox->chave;
}

int isAlpha(char x)
{
    if(x >= 'A' && x <= 'Z') return 1;
    return 0;
}

int get_precedence(char x)
{
    switch(x)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int main()
{
    char xs[501];
    scanf(" %s", xs);

    fila * f = cria_fila();
    pilha * p = cria_pilha();

    int par = 0, par_flag = 1;
    int size = strlen(xs);
    for(int i = 0; i < size; i++)
    {
        char x = xs[i];

        if(isAlpha(x)) f = enfileira(f, x);

        else if(x == '(') {empilha(p, x); par++;}

        else if(x == ')')
        {
            par--;
            if(par < 0) par_flag = 0;

            char x2;
            while(desempilha(p, &x2) && x2 != '(')
            {
                f = enfileira(f, x2);
            }
        }

        else
        {
            char x2 = topo(p);
            while(x2 != ' ' && 
                    (get_precedence(x2) > get_precedence(x) ||
                        (get_precedence(x2) == get_precedence(x) && x != '^')))
            {
                desempilha(p, &x2);
                f = enfileira(f, x2);
                x2 = topo(p);
            }
            empilha(p, x);
        }
    }

    if(par) par_flag = 0;

    if(!par_flag)
    {
        printf("incorretamente parentizada\n");
        return 0;
    }

    while(p->prox != NULL)
    {
        char x2;
        desempilha(p, &x2);
        f = enfileira(f, x2);
    }

    fila * atual = f->prox;
    while(atual != f)
    {
        printf("%c", atual->dado);
        atual = atual->prox;
    }

    printf("\n");

    destroi_fila(f);
    destroi_pilha(p);
    free(f);
    free(p);
    return 0;
}