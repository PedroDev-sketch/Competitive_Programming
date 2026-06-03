#include <stdio.h>
#include <stdlib.h>

int binary_search(int * xs, int l, int r, int k)
{
    if(abs(r-l) <= 1)
    {
        if(xs[l] == k) return l;
        else if(xs[r] == k) return r;
        else return -1;
    }

    int m = l + (r-l)/2;

    if(k > xs[m]) return binary_search(xs, m, r, k);
    else return binary_search(xs, l, m, k);
}

void generate_array(int * xs, int n)
{
    for(int i = 1; i < n; i++)
    {
        xs[i] = i;
        printf("%d ", xs[i]);
    }
    printf("\n");
}

int main()
{
    int n = 10;
    int *xs = malloc(n * sizeof(*xs));

    generate_array(xs, n);

    int k = xs[5];
    int pos = binary_search(xs, 0, n-1, k);
    printf("%d\n", pos);

    free(xs);

    return 0;
}