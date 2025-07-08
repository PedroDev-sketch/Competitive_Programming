#include <stdio.h>
#include <stdlib.h>

void for_recursivo(int * xs, int start, int end)
{
    if(start==end) return;

    printf("%d ", xs[start]);
    for_recursivo(xs, start+1, end);
}

int main()
{
    int * xs = malloc(20 * sizeof(*xs));

    //For só sendo usado pra preencher o array;
    for(int i = 1; i <= 20; i++) xs[i-1] = i; 

    for_recursivo(xs, 0, 20);
    printf("\n");

    return 0;
}