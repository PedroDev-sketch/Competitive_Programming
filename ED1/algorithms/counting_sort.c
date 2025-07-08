#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define swap(a, b) {int temp = a; a = b; b = temp;}
#define oo 1000000000

void counting_sort(int * xs, int n, int a, int b)
{
    int tam = b - a;

    if(tam < 0) tam *= (-1);

    int * aux = calloc(tam, sizeof(*aux));

    for(int i = 0; i < n; i++) aux[xs[i] - a]++;

    for(int i = 0, j = 0; i <= tam; i++)
    {
        while(aux[i] > 0)
        {
            xs[j] = i+a; j++; aux[i]--;
        }
    }
    free(aux);
}

void generate_array(int * xs, int n)
{
    for(int i = 0; i < n; i++)
    {
        xs[i] = rand() % 101;
        printf("%d ", xs[i]);
    }
    printf("\n");
}

void print_array(int * xs, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", xs[i]);
    }
    printf("\n");
}

int main()
{
    int n = 10;
    int * xs = malloc(n * sizeof(*xs));
    generate_array(xs, n);


    print_array(xs, n);

    free(xs);

    return 0;
}