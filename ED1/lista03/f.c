#include <stdio.h>
#include <stdlib.h>

typedef struct Coordinate
{
    long long x;
    long long y;
} Coordinate;

void swap(Coordinate * a, Coordinate * b)
{
    Coordinate temp = *a;
    *a = *b;
    *b = temp;
}

long long partition(Coordinate * xs, long long l, long long r)
{
    long long i = l, a = xs[r].x, b = xs[r].y;
    long long pivot_dist = a*a + b*b;

    for(long long j = l; j <= r-1; j++)
    {
        long long curr_dist = xs[j].x*xs[j].x + xs[j].y*xs[j].y;
        if(curr_dist < pivot_dist)
        {
            swap(&xs[i], &xs[j]);
            i++;
        }
    }
    swap(&xs[i], &xs[r]);

    return i;
}

void quick_sort(Coordinate * xs, long long l, long long r)
{
    if(l < r)
    {
        long long index = partition(xs, l, r);
        quick_sort(xs, l, index-1);
        quick_sort(xs, index+1, r);
    }
}

int main()
{
    long long c, t, pts= 0;
    scanf("%lld %lld", &c, &t);

    long long * cs = malloc(c * sizeof(*cs));

    for(long long i = 0; i < c; i++) scanf("%lld", &cs[i]);

    Coordinate * xs = malloc(t * sizeof(*xs));

    for(long long i = 0; i < t; i++)
    {
        scanf("%lld %lld", &xs[i].x, &xs[i].y);
        xs[i].x = abs(xs[i].x), xs[i].y = abs(xs[i].y);
    }

    quick_sort(xs, 0, t-1);

    //for(long long i = 0; i < t; i++) printf("%lld %lld\n", xs[i].x, xs[i].y);

    long long cindex = c-1, ccount = 0, savecount = 0;
    for(long long i = t-1; i >= 0; i--)
    {
        Coordinate p = xs[i];

        while(p.x*p.x + p.y*p.y <= cs[cindex]*cs[cindex] && cindex>=0) {cindex--; ccount++;}
        pts += ccount;

        //printf("%lld %lld <- Debug\n", pts, cs[cindex]);
    }

    printf("%lld\n", pts);
    free(cs), free(xs);

    return 0;
}