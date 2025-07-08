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
    if(topo == NULL) return 1;

    *y = topo->dado;
    f->prox = topo->prox;

    free(topo);
    return 0;
}

celula* cria_pilha()
{
    celula *f = malloc(sizeof(celula));
    f->prox = NULL;
    return f;
}

void destroi_pilha(celula *f)
{
    char y;
    while(desempilha(f, &y) == 0); 
    free(f);
}

int precedencia(char op) 
{
    switch (op) 
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int main() {
    char eq[501];
    scanf("%s", eq);

    celula *f = cria_pilha();
    char posfixa[501] = {0}; 
    int posfixa_idx = 0;
    int parenteses_count = 0;

    for (int i = 0; eq[i] != '\0'; i++) {
        char token = eq[i];

        if (token >= 'A' && token <= 'Z') posfixa[posfixa_idx++] = token;

        else if (token == '(') 
        {
            empilha(f, token);
            parenteses_count++;
        } 

        else if (token == ')') 
        {
            parenteses_count--;
            if (parenteses_count < 0) 
            { 
                printf("incorretamente parentizada\n");
                destroi_pilha(f);
                return 0;
            }
            char topo;
    
            while (f->prox != NULL && f->prox->dado != '(') 
            {
                desempilha(f, &topo);
                posfixa[posfixa_idx++] = topo;
            }

            if (f->prox != NULL) desempilha(f, &topo); // largar o '('
            
        } 
        
        else 
        {
            while (f->prox != NULL && 
                    (precedencia(f->prox->dado) > precedencia(token) || (precedencia(f->prox->dado) == precedencia(token) && token != '^'))
                ) 
            {
                char topo;
                desempilha(f, &topo);
                posfixa[posfixa_idx++] = topo;
            }
            empilha(f, token);
        }
    }

    if (parenteses_count != 0) 
    {
        printf("incorretamente parentizada\n");
        destroi_pilha(f);
        return 0;
    }

    while (f->prox != NULL) 
    {
        char topo;
        desempilha(f, &topo);
        posfixa[posfixa_idx++] = topo;
    }

    printf("%s\n", posfixa);

    destroi_pilha(f);

    return 0;
}