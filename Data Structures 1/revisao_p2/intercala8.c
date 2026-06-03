#include <stdio.h>
#include <stdlib.h>

void countingsort(int * xs, int n, int a, int b)
{
    int tam = b - a;
    if(tam<0) tam*=(-1);

    int * ys = calloc(tam, sizeof(*ys));
    for(int i = 0; i < n; i++) ys[xs[i] - a]++;

    for(int i = 0, j = 0; i <= tam; i++)
    {
        while(ys[i])
        {
            xs[j] = i + a; 
            j++;
            ys[i]--;
        }
    }

    free(ys);
}

int main()
{
    int t = 8;
    int * xs = malloc(800007 * sizeof(*xs));
    int index = 0;

    int small = 100000000;
    int big = -1;

    while(t--)
    {
        int num;
        scanf("%d", &num);

        for(int i = 0; i < num; i++)
        {
            scanf("%d", &xs[index]);

            if(xs[index] > big) big = xs[index];
            if(xs[index] < small) small = xs[index];

            index++;
        }
    }

    countingsort(xs, index, small, big);

    for(int i = 0; i < index; i++) printf("%d ", xs[i]);
    printf("\n");
    free(xs);
    return 0;
}