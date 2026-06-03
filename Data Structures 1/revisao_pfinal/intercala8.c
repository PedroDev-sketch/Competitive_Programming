#include <stdio.h>
#include <stdlib.h>

void counting_sort(int * xs, int n, int a, int b)
{
    int tam = b - a;

    if(tam < 0) tam *= (-1);

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
    int * xs = malloc(800007 * sizeof(int));
    int idx = 0;

    int maior = -1, menor = 10000000;

    for(int i = 0; i < 8; i++)
    {
        int n;
        scanf("%d", &n);

        for(int j = 0; j < n; j++)
        {
            scanf("%d", &xs[idx]);

            if(xs[idx] > maior) maior = xs[idx];
            if(xs[idx] < menor) menor = xs[idx];

            idx++;
        }
    }

    counting_sort(xs, idx, menor, maior);

    for(int i = 0; i < idx; i++)
    {
        printf("%d ", xs[i]);
    }

    printf("\n");

    free(xs);
    return 0;
}