#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {int temp = b; b = a; a = temp;}

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

void quick_sort(int * xs, int l, int r)
{
    if(l < r)
    {
        int index = partition(xs, l, r);

        quick_sort(xs, l, index-1);
        quick_sort(xs, index+1, r);
    }
}

void quick_select(int * xs, int l, int r, int k)
{
    if(l < r)
    {
        int index = partition(xs, l, r);

        if(index < k) quick_select(xs, index+1, r, k);
        else if(index > k) quick_select(xs, l, index-1, k);
        else return;
    }
}

int main()
{
    int n, p, x;
    scanf("%d %d %d", &n, &p, &x);

    int * xs = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &xs[i]);

    int start = p * x; //Indexado em zero
    int end = start + x - 1;

    quick_select(xs, 0, n-1, start);
    quick_select(xs, start, n-1, end);

    quick_sort(xs, start, end);
    for(int i = start; i <= end && i < n; i++)
    {
        printf("%d\n", xs[i]);
    }

    free(xs);
    return 0;
}