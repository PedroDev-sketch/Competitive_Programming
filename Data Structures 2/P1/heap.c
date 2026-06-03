#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b) {int temp = b; b = a; a = temp;}

typedef struct heap
{
    int * v;
    int tam, n;
}heap;

heap* init(int tam)
{
    heap* h = malloc(sizeof(heap));
    h->v = malloc(tam*sizeof(int));
    h->tam=tam;
    h->n = 1;
}

void fixup(heap* h, int i)
{
    int parent = i/2;
    if(parent < 1) return;

    if(h->v[parent] < h->v[i])
        swap(h->v[parent], h->v[i]);
    
    fixup(h, parent);
}

void push(heap* h, int x)
{
    if(h->n > h->tam)
    {
        h->tam *= 2;
        h->v = realloc(h->v,  h->tam*sizeof(int));
    }

    h->v[h->n] = x;
    fixup(h, h->n);
    h->n++;
}

void fixdown(heap* h, int k)
{
    int esq = 2*k; int dir = 2*k + 1;

    int child = esq;
    if(dir < h->n && h->v[dir] > h->v[esq])
        child++;
    
    if(child >= h->n) return;
    
    if(h->v[child] > h->v[k])
        swap(h->v[child], h->v[k]);
    
    fixdown(h, child);
}

int pop(heap* h)
{
    int num = h->v[1];

    h->n--;
    h->v[1] = h->v[h->n];

    fixdown(h, 1);
    return num;
}

int main()
{
    heap* fp = init(100);
    push(fp, 10);
    push(fp, 30);
    push(fp, 20);
    push(fp, 40);

    for(int i = 0; i < 4; i++)
    {
        int num = pop(fp);
        printf("-> %d\n", num);
    }
    return 0;
}