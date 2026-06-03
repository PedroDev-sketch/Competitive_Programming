#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char dado;
    struct celula *prox;
} celula;

void empilha(celula *f, char x) 
{
    celula *nova = malloc(sizeof(celula));

    nova->dado = x;
    nova->prox = f->prox;

    f->prox = nova;
}

int desempilha(celula * f, char * y)
{
    celula * topo = f->prox;
    if(topo == NULL) return 1; //deu ruim

    *y = topo->dado;
    f->prox = topo->prox;
    free(topo);

    return 0; // deu bao
}

void destroi_pilha(celula * f)
{
    celula * atual = f;

    while(atual != NULL)
    {
        celula * lixo = atual;
        atual = atual->prox;
        free(lixo);
    }
}

celula * cria_pilha()
{
    celula * f = malloc(sizeof(celula));
    f->prox = NULL;
    return f;
}

int main()
{
    char * eq = malloc(501*sizeof(char));
    scanf(" %s", eq);

    celula * f = cria_pilha();

    int ans = 1;
    for(int i = 0; i<=500 && eq[i] != '\0' && ans; i++)
    {
        if(eq[i] == '[' || eq[i] == '{' || eq[i] == '(')
        {
            empilha(f, eq[i]);
        }

        else if(eq[i] == ']' || eq[i] == '}' || eq[i] == ')')
        {
            char comp = ' ';
            if(desempilha(f, &comp))
                ans = 0;
            else
            {
                if(eq[i] == ')' && comp+1 != eq[i]) ans = 0;
                else if(eq[i] != ')' && comp+2 != eq[i]) ans = 0;
            }
        }
    }

    if(f->prox != NULL) ans = 0;
    destroi_pilha(f);
    free(eq);

    char output[16];
    sprintf(output, "%s\n", (ans ? "sim" : "nao"));
    printf(output);

    return 0;
}