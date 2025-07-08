#include <stdio.h>
#include <stdlib.h>


int binary_search(int * xs, int l, int r, int k)
{
    if(abs(r-l) <= 1)
    {
        if(xs[l] > k) return l;
        else return r;
    }

    int mid = l + (r-l)/2;

    if(xs[mid] < k) return binary_search(xs, mid, r, k);
    else return binary_search(xs, l, mid, k);
}

int main()
{
    int op, n, size=0, capacity=0;
    int * xs = NULL;

    while(scanf("%d %d", &op, &n) != EOF)
    {
        if(op == 1)
        {
            if(size >= capacity)
            {
                capacity = (!capacity) ? 1 : capacity*2;
                int * buffer = realloc(xs, capacity*sizeof(int));
                xs = buffer;
            }

            int pos = binary_search(xs, 0, size, n);
            for(int i = size; i > pos; i--) xs[i] = xs[i-1];
            xs[pos]=n;
            size++;
        }
        else
        {
            for(int i = 0; i < n-1; i++) printf("%d ", xs[i]);
            printf("%d\n", xs[n-1]);
        }
    }

    free(xs);

    return 0;
}