#include <stdio.h>
#include <stdlib.h>

int binary_search(int * xs, int l, int r, int num)
{
    if(abs(r-l) <= 1)
    {
        if(xs[r] < num) return r+1;

        if(xs[l] >= num) return l;
        else return r;
    }

    int mid = l + (r-l)/2;

    if(xs[mid] >= num)
        return binary_search(xs, l, mid, num);
    else   
        return binary_search(xs, mid, r, num);
}

int main()
{
    int n, m;
    scanf("%d %d", &n,&m);

    int * xs = malloc(n * sizeof(*xs));

    for(int i = 0; i < n; i++) scanf("%d", &xs[i]);

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