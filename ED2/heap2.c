#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int* v;
    int tam, n;
}heap;

heap* init(int tam)
{
    heap * h = malloc(sizeof(heap));
    h->v = malloc(tam * sizeof(int));
    h->tam = tam;
    h->n = 1;
}

void push(heap* h, int x)
{

}