#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int select(int * xs, int l, int r)
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

int quick_select(int * xs, int l, int r, int k)
{
    int index = select(xs, 0, r);

    if(xs[index] < k)
    {

    }

    else
    {
        
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n,&m);

    int * xs = malloc(n * sizeof(*xs));

    for(int i = 0; i < n; i++) scanf("%d", &xs[i]);

    for(int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);

        int ans = quick_select(xs, 0, n-1, k);
        printf("%d\n", ans);
    }

    free(xs);

    return 0;
}