#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha
{
    char * str;
    struct pilha * prox;
}pilha;

pilha * cria_pilha()
{
    pilha * f = malloc(sizeof(pilha));
    f->prox = NULL;
    return f;
}

void empilha(pilha * f, char * entrada)
{
    pilha * nova = malloc(sizeof(pilha));

    nova->str = entrada;
    nova->prox = f->prox;
    f->prox = nova;
}

char * desempilha(pilha * f)
{
    if(f->prox == NULL) return NULL;

    pilha * lixo = f->prox;
    char * saida = lixo->str;
    f->prox = lixo->prox;
    free(lixo);

    return saida;
}

void destroi_pilha(pilha * f)
{
    pilha * atual = f->prox;
    while(atual != NULL)
    {
        pilha * lixo = atual;
        atual = atual->prox;
        free(lixo->str);
        free(lixo);
    }
}

int main()
{
    pilha * f = cria_pilha();

    char * operacao = malloc(20 * sizeof(char));
    while(scanf(" %s", operacao) != EOF)
    {
        if(!strcmp(operacao, "inserir"))
        {
            char * entrada =  malloc(102 * sizeof(char));
            scanf(" %[^\n]", entrada);

            empilha(f, entrada);
        }

        else
        {
            char * saida = desempilha(f);

            if(saida != NULL)
            {
                printf("%s\n", saida);
                free(saida);
            }
            else printf("NULL\n");
        }
    }

    destroi_pilha(f);
    free(operacao);
    free(f);

    return 0;
}