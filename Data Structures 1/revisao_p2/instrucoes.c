#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {instruction temp = a; a = b; b = temp;}

typedef struct instruction
{
    int code;
    char str[16];
}instruction;

int partition(instruction * xs, int l, int r)
{
    int x = xs[r].code;
    int i = l;

    for(int j = l; j <= r-1; j++)
    {
        if(xs[j].code < x)
        {
            swap(xs[i], xs[j]);
            i++;
        }
    }
    swap(xs[i], xs[r]);
    return i;
}

void quick_sort(instruction * xs, int l, int r)
{
    if(l < r)
    {
        int index = partition(xs, l, r);
        quick_sort(xs, l, index-1);
        quick_sort(xs, index+1, r);
    }
}

char * binary_search(instruction * xs, int l, int r, int k)
{
    if(abs(r-l) <= 1)
    {
        if(xs[l].code == k) return xs[l].str;
        if(xs[r].code == k) return xs[r].str;
        return "undefined";
    }

    int m = l + (r-l)/2;

    if(xs[m].code > k) return binary_search(xs, l, m, k);
    else return binary_search(xs, m, r, k);
}

int main()
{
    int n;
    scanf("%d", &n);

    instruction * xs = malloc(n * sizeof(*xs));

    for(int i = 0; i < n; i++)
    {
        scanf("%d %s", &xs[i].code, &xs[i].str);
    }

    quick_sort(xs, 0, n-1);;

    int num;
    while(scanf("%d", &num) != EOF)
    {
        char * ans = binary_search(xs, 0, n-1, num);
        printf("%s\n", ans);
    }

    free(xs);

    return 0;
}