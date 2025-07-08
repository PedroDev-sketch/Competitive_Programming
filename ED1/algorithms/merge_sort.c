#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define swap(a, b) {int temp = a; a = b; b = temp;}
#define oo 1000000000

void merge(int * xs, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;

    int L[n1], R[n2];

    int i, j, k;
    for(i = 0; i < n1; i++)
    {
        L[i] = xs[l+i];
    }

    for(j = 0; j < n2; j++)
    {
        R[j] = xs[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            xs[k] = L[i];
            i++;
        }
        else
        {
            xs[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    { 
        xs[k] = L[i]; 
        i++;
        k++;
    }
    while(j < n2) 
    {
        xs[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int * xs, int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;

        merge_sort(xs, l, m);
        merge_sort(xs, m+1, r);

        merge(xs, l, m, r);
    }
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

    merge_sort(xs, 0, n - 1);

    print_array(xs, n);

    free(xs);

    return 0;
}