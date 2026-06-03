#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//UTILS


void array_read(int * xs, int n)
{
    for(int i = 0; i < n; i++)
        scanf(" %d", &xs[i]);
}

void string_read(char * xs, int n)
{
    for(int i = 0; i < n; i++)
        scanf(" %c", &xs[i]);
}


//SOLDADO


typedef struct soldado
{
    int vida;
    int index;
    int arq;
} soldado;


// PILHA


typedef struct pilha 
{
    soldado* dado;
    struct pilha* prox;
} pilha;

void empilha(pilha *f, soldado *x) 
{
    pilha *nova = malloc(sizeof(pilha));

    nova->dado = x;
    nova->prox = f->prox;

    f->prox = nova;
}

int desempilha(pilha * f)
{
    pilha * topo = f->prox;
    if(topo == NULL) return 1;

    f->prox = topo->prox;
    free(topo->dado);
    free(topo);

    return 0; 
}

void destroi_pilha(pilha * f)
{
    pilha * atual = f->prox;

    while(atual != NULL)
    {
        pilha * lixo = atual;
        atual = atual->prox;
        free(lixo->dado);
        free(lixo);
    }

    free(f);
}

pilha * cria_pilha()
{
    pilha * f = malloc(sizeof(pilha));
    f->prox = NULL;
    return f;
}

soldado * topo(pilha* p)
{
    if(p == NULL || p->prox == NULL)
        return NULL;

    return p->prox->dado;
}


//FILA


typedef struct fila
{
    soldado * dado;
    struct fila * prox;
    struct fila * tail;
}fila;

fila * cria_fila()
{
    fila * f = malloc(sizeof(fila));
    f->dado = NULL;
    f->prox = NULL;
    f->tail = f;
    return f;
}

fila * insere(fila *f, soldado *x) 
{
    fila *nova = malloc(sizeof(fila));
    if (nova == NULL) return NULL;

    nova->dado = x;
    nova->prox = NULL;

    f->tail->prox = nova;
    f->tail = nova;
    
    return f;
}

int pop(fila * f)
{
    fila * atual = f->prox;
    if(atual == NULL) return 0;

    f->prox = atual->prox;

    if(f->prox == NULL)
        f->tail = f;

    free(atual->dado);
    free(atual);
    return 1;
}

void destroi_fila(fila * f)
{
    fila * atual = f->prox;
    while(atual != NULL)
    {
        fila * lixo = atual;
        atual = atual->prox;
        free(lixo->dado);
        free(lixo);
    }
    free(f);
}

soldado * frente(fila* f)
{
    if(f == NULL || f->prox == NULL)
        return NULL;

    return f->prox->dado;
}


//MAIN


int main()
{
    int n; scanf("%d", &n);

    pilha* p = cria_pilha();
    fila* f = cria_fila();

    int * a = malloc(n * sizeof(int));
    char * b = malloc(n * sizeof(char));
    int * c = malloc(n * sizeof(int));
    array_read(a, n); string_read(b, n); array_read(c, n);

    for(int i = 0; i < n; i++)
    {
        soldado * sldr = malloc(sizeof(soldado));
        sldr->vida = a[i];
        sldr->index = i+1;
        sldr->arq = c[i];
 
        if(b[i]=='l')
            empilha(p, sldr);
        else
            insere(f, sldr);
    }

    char resp1[] = "Legiao", resp2[] = "Horda", resp3[] = "Empate";

    while(frente(f) != NULL && topo(p) != NULL)
    {
        soldado * horda = frente(f); soldado * legiao = topo(p);

        if(horda->arq == legiao->index && legiao->arq == horda->index)
        {
            desempilha(p);
            pop(f);
            continue;
        }
        
        if(legiao->arq == horda->index)
        {
            pop(f);
            continue;
        }

        if(horda->arq == legiao->index)
        {
            desempilha(p);
            continue;
        }

        if(legiao->vida > horda->vida)
        {
            legiao->vida -= horda->vida;
            pop(f);
            continue;
        }

        if(legiao->vida < horda->vida)
        {
            horda->vida -= legiao->vida;
            desempilha(p);
            continue;
        }

        else
        {
            desempilha(p);
            pop(f);
            continue;
        }
    }

    if(f->prox == NULL && p->prox == NULL)
        printf("%s\n", resp3);
    else if(f->prox == NULL)
        printf("%s\n", resp1);
    else
        printf("%s\n", resp2);
        
    destroi_pilha(p);
    destroi_fila(f);
    free(a); free(b); free(c);

    return 0;
}