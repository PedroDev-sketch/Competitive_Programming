#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila
{
    char * str;
    struct fila * prox;
}fila;

fila * cria_fila()
{
    fila * f = malloc(sizeof(fila));
    f->prox = NULL;
    return f;
}

fila * insere(fila *f, char * cidade)
{
    fila * nova = malloc(sizeof(fila));
    nova->str = cidade;
    nova->prox = f->prox;
    f->prox = nova;
    return nova;
}

char * pop(fila * f)
{
    fila * atual = f->prox;
    if(atual == NULL) return NULL;

    char * saida = atual->str;
    f->prox = atual->prox;
    free(atual);

    return saida;
}

void destroi_fila(fila * f)
{
    fila * atual = f->prox;
    while(atual !=NULL)
    {
        fila * lixo = atual;
        atual = atual->prox;
        free(lixo->str);
        free(lixo);
    }
}

int main()
{
    //65 - A, 97 - a

    fila * f = cria_fila();
    fila * l = f;

    char temp_entrada[27];

    while(scanf(" %s", temp_entrada) != EOF)
    {
        char * entrada = malloc(strlen(temp_entrada) + 1);
        strcpy(entrada, temp_entrada);
        l = insere(l, entrada);
    }

    char last = '\0';
    while(f->prox != NULL)
    {
        char * saida = pop(f);
        if(saida[0] + 32 == last)
        {
            l = insere(l, saida);
            last = '\0';
        }
        else 
        {
            printf("%s\n", saida);
            int size = strlen(saida);
            last = saida[size-1];
            free(saida);
        }
    }

    destroi_fila(f);
    free(f);
    return 0;
}