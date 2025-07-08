#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {int temp = a; a = b; b = temp;}

int partition(int * xs, int l, int r)
{
    int x = xs[r], i = l;

    for(int j = l; j <= r-1; j++)
    {
        if(xs[j] < x)
        { 
            swap(xs[i], xs[j]);
            i++;
        }
    }

    swap(xs[i], xs[r]);
    return i;
}

void quick_select(int * xs, int l, int r, int k)
{
    if(l < r)
    {
        int index = partition(xs, l, r);

        if(index == k) return;

        if(index < k) quick_select(xs, index+1, r, k);
        else quick_select(xs, l, index-1, k);
    }
}

void quick_sort(int * xs, int l, int r)
{
    if(l < r)
    {
        int index = partition(xs, l, r);

        quick_sort(xs, index+1, r);
        quick_sort(xs, l, index-1);
    }
}

int main()
{
    int n, p, x;
    scanf("%d %d %d", &n, &p, &x);

    int * xs = malloc(n * sizeof(*xs));

    for(int i = 0; i < n; i++) scanf("%d", &xs[i]);

    int low_bound = x*p, up_bound = x*p + x - 1;
    quick_select(xs, 0, n-1, low_bound);
    quick_select(xs, x*p, n-1, up_bound);

    quick_sort(xs, low_bound, up_bound);

    for(int i = x*p; i < x*p+x && i < n; i++)
    {
        printf("%d\n", xs[i]);
    }

    free(xs);
    return 0;
}