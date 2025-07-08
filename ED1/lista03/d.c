#include <stdio.h>
#include <stdlib.h>

typedef struct Cell
{
    int val;
    int index;
} Cell;

void swap(Cell * a, Cell * b)
{
    Cell temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Cell * xs, int l, int r)
{
    int x = xs[r].val, i = l;

    for(int j = l; j <= r-1; j++)
    {
        if(xs[j].val < x)
        {
            swap(&xs[i], &xs[j]);
            i++;
        }
    }
    swap(&xs[i], &xs[r]);

    return i;
}

void quick_sort(Cell * xs, int l, int r)
{
    if(l<r)
    {
        int index = partition(xs, l, r); 

        quick_sort(xs, l, index-1);
        quick_sort(xs, index+1, r);
    }   
}

int binary_search(Cell * xs, int l, int r, int num)
{
    if(abs(r-l) <= 1)
    {
        if(xs[l].val == num) return xs[l].index;
        else if(xs[r].val == num) return xs[r].index;
        else return -1;
    }

    int mid = l + (r-l)/2;

    if(xs[mid].val >= num)
        return binary_search(xs, l, mid, num);
    else   
        return binary_search(xs, mid, r, num);
} 

int main()
{
    int n, m;
    scanf("%d %d", &n,&m);

    Cell * xs = malloc(n * sizeof(*xs));

    for(int i = 0; i < n; i++) {scanf("%d", &xs[i].val); xs[i].index = i;}

    quick_sort(xs, 0, n-1);

    for(int i = 0; i < m; i++)
    {
        int num;
        scanf("%d", &num);

        int ans = binary_search(xs, 0, n-1, num);
        printf("%d\n", ans);
    }

    free(xs);

    return 0;
}