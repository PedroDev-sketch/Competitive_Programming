#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define swap(a, b) { ll t = a; a = b; b = t; }

ll read_ll() {
    ll x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

void print_ll(ll x) {
    if (x == 0) { putchar('0'); putchar('\n'); return; }
    char buf[20];
    int i = 0;
    while (x) {
        buf[i++] = '0' + x % 10;
        x /= 10;
    }
    while (i--) putchar(buf[i]);
    putchar('\n');
}

ll partition(ll * xs, ll l, ll r)
{
    ll i = l, x = xs[r];
    for(ll j = l; j <= r-1; j++)
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

void quick_sort(ll * xs, ll l, ll r)
{
    if(l<r)
    {
        ll index = partition(xs, l, r);
        quick_sort(xs, index+1, r);
        quick_sort(xs, l, index-1);
    }
}

int main()
{
    ll n = read_ll(), p = read_ll(), x = read_ll();

    ll * xs = malloc(n * sizeof(*xs));
    for(ll i = 0; i < n; i++) xs[i] = read_ll();

    quick_sort(xs, 0, n-1);

    for(int i = 0; i < x && (x*p + i) < n; i++)
    {
        print_ll(xs[x*(p) + i]);
    }

    free(xs);
    return 0;
}