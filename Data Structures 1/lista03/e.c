#include <stdio.h>
#include <stdlib.h>

typedef struct Casa
{
    int num;
    int index;
} Casa;

void swap(Casa * a, Casa * b)
{
    Casa temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Casa * xs, int l, int r)
{
    int x = xs[r].num, i = l;
    for(int j = l; j <= r-1; j++)
    {
        if(xs[j].num < x)
        {
            swap(&xs[i], &xs[j]);
            i++;
        }
    }
    swap(&xs[i], &xs[r]);

    return i;
}

void quick_sort(Casa * xs, int l, int r)
{
    if(l < r)
    {
        int index = partition(xs, l, r);
        quick_sort(xs, index+1, r);
        quick_sort(xs, l, index-1);
    }
}

int binary_search(Casa * xs, int l, int r, int k)
{
    if(abs(r-l) <= 1)
    {
        if(xs[l].num == k) return xs[l].index;
        else return xs[r].index;
    }

    int mid = l + (r-l)/2;

    if(xs[mid].num < k) return binary_search(xs, mid, r, k);
    else return binary_search(xs, l, mid, k);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Casa * xs = malloc(n * sizeof(*xs));

    for(int i = 0; i < n; i++) {scanf("%d", &xs[i].num); xs[i].index = i;}

    quick_sort(xs, 0, n-1);

    int time = 0, dist = 0, last = 0;
    for(int i = 0; i < m; i++) 
    {
        int p;
        scanf("%d", &p);

        dist = binary_search(xs, 0, n-1, p);

        time += abs(dist - last);

        last = dist;
    }

    printf("%d\n", time);

    free(xs);

    return 0;
}