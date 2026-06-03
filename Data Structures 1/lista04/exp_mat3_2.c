#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>

#define ll long long

long long variables[26];

typedef struct pilha
{
    char dados;
    struct pilha * prox;
} pilha;

typedef struct pilha_num
{
    ll dados;
    struct pilha_num * prox;
} pilha_num;

typedef struct fila
{
    char dados;
    struct fila * prox;
}fila;

pilha *cria_pilha()
{
    pilha *f = malloc(sizeof(pilha));
    f->prox = NULL;
    return f;
}

pilha_num *cria_pilha_num()
{
    pilha_num *f = malloc(sizeof(pilha_num));
    f->prox = NULL;
    return f;
}

fila *cria_fila()
{
    fila *f = malloc(sizeof(fila));
    f->prox = f;
    return f;
}

void empilha(pilha *f, char dados)
{
    pilha *nova = malloc(sizeof(pilha));

    nova->dados = dados;

    nova->prox = f->prox;
    f->prox = nova;
}

void empilha_num(pilha_num *f, ll dados)
{
    pilha_num *nova = malloc(sizeof(pilha_num));

    nova->dados = dados;

    nova->prox = f->prox;
    f->prox = nova;
}

fila * enfileira(fila *f, char x) 
{
    fila *nova = malloc(sizeof(fila));
    if (nova == NULL) return NULL;
    nova->prox = f->prox;

    if(f==NULL) return NULL;
    f->dados = x;
    f->prox = nova;
    return nova;
}

long long desempilha(pilha *f, char *dados)
{
    pilha *lixo = f->prox;
    if (lixo == NULL)
        return 0;

    *dados = lixo->dados;

    f->prox = lixo->prox;
    free(lixo);

    return 1;
}

long long desempilha_num(pilha_num *f, ll *dados)
{
    pilha_num *lixo = f->prox;
    if (lixo == NULL)
        return 0;

    *dados = lixo->dados;

    f->prox = lixo->prox;
    free(lixo);

    return 1;
}

fila * desenfileira(fila *f, char * x) 
{
    if(f->prox == f) return NULL;
    
    fila * lixo = f->prox;
    *x = lixo->dados;
    f->prox = lixo->prox;
    free(lixo);
    return f;
}

void destroi_fila(fila * f)
{
    fila * atual = f->prox;
    while(atual != f)
    {
        fila *lixo = atual;
        atual = atual->prox;

        free(lixo);
    }
}

void destroi_pilha(pilha *f)
{
    pilha *atual = f->prox;
    while (atual != NULL)
    {
        pilha *lixo = atual;
        atual = atual->prox;
        free(lixo);
    }
}

void destroi_pilha_num(pilha_num *f)
{
    pilha_num *atual = f->prox;
    while (atual != NULL)
    {
        pilha_num *lixo = atual;
        atual = atual->prox;
        free(lixo);
    }
}

long long isAlpha(char x)
{
    if (x >= 'A' && x <= 'Z')
        return 1;
    return 0;
}

long long get_value(char x)
{
    return variables[x - 'A'];
}

long long get_precedence(char op)
{
    switch (op)
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

long long operate(long long a, long long b, char op)
{
    switch (op)
    {
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    case '*':
        return (a * b);
    case '/':
        return (a / b);
    case '^':
        return (pow(a, b));
    default:
        break;
    }
}

char topo(pilha * f)
{
    if(f->prox == NULL) return ' ';
    return f->prox->dados;
}

char frente(fila * f)
{
    if(f->prox == f) return ' ';
    return f->prox->dados;
}

long long main()
{
    char *entrada = malloc(501 * sizeof(char));
    scanf(" %s", entrada);

    long long size = strlen(entrada);

    memset(variables, -1, 26);

    char var;
    long long val;
    while (scanf(" %c=%lld", &var, &val) == 2)
    {
        variables[var - 'A'] = val;
    }

    pilha *p = cria_pilha();
    fila * f = cria_fila();

    ll parenteses = 0;
    ll par_check = 1;

    for(ll i = 0; i < size; i++)
    {
        char x = entrada[i];
        if(isAlpha(x))
        {
            f = enfileira(f, x);
        }

        else if(x == '(') 
        {
            empilha(p, x);
            parenteses++;
        }

        else if(x == ')')
        {
            parenteses--;
            if(parenteses < 0) par_check = 0;

            char buff = topo(p);

            while(buff != ' ' && buff != '(') 
            {
                desempilha(p, &buff);
                f = enfileira(f, buff);
                buff = topo(p);
            }

            if(topo(p) == '(') desempilha(p, &buff);
        }

        else
        {
            char buff;
            buff = topo(p);

            while(buff != ' ' && 
                (get_precedence(buff) > get_precedence(x)) ||
                ((get_precedence(buff) == get_precedence(x) && x != '^'))
                )
            {
                desempilha(p, &buff);
                f = enfileira(f, buff);
                buff = topo(p);
            }

            empilha(p, x);
        }
    }

    if(parenteses) par_check = 0;

    char buff = topo(p);
    while(buff != ' ')
    {
        desempilha(p, &buff);
        f = enfileira(f, buff);
        buff = topo(p);
    }

   if(!par_check) printf("emf\n");

   else
   {
       pilha_num * p_num = cria_pilha_num(); 

        char buff = frente(f);
        while(buff != ' ')
        {
            desenfileira(f, &buff);

            if(isAlpha(buff))
            {
                ll x = get_value(buff);
                empilha_num(p_num, x);
            }

            else
            {
                ll num1, num2;
                desempilha_num(p_num, &num1);
                desempilha_num(p_num, &num2);
                ll num_res = operate(num2, num1, buff);
                empilha_num(p_num, num_res);
            }

            buff = frente(f);
        }

        ll ans = 0;
        if(p_num->prox != NULL) ans = p_num->prox->dados;

        printf("%lld\n", ans);

       destroi_pilha_num(p_num);
       free(p_num);
   }

    destroi_pilha(p);
    destroi_fila(f);
    free(entrada);
    free(p);
    free(f);
    return 0;
}