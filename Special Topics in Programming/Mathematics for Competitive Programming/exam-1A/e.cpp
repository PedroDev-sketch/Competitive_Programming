#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

const ll MAXN = 1e6+10;
vll primes;

void sieve()
{
    vll check(MAXN, 0);
    for(ll i = 2; i < MAXN; ++i)
    {
        if(check[i])
            continue;
        primes.emplace_back(i);
        for(ll j = i; j < MAXN; j += i)
            check[j] = 1;
    }
}

long double pi(ll n)
{
    if(n <= 1) return 0;
    return ((long double)n / log(n));
}

void solve()
{
    ll a, b; cin >> a >> b;
    vector<bool> composite(b - a + 1, false);
    if (a == 1) composite[0] = true;
    for(auto p : primes)
    {
        if(p*p > b) break;
        ll st = ((a + p - 1)/p)*p;
        if (st < p * p) st = p * p;
        for(ll i = st; i <= b; i += p)
            composite[i-a] = true;
    }

    ll pnum = 0;
    for(auto c : composite)
        if(!c)
            ++pnum;

    long double num = pi(b) - pi(a-1);  
    cout << fixed << setprecision(7) << (long double)pnum - num << '\n';      
}

signed main()
{
    fio;
    sieve();
    ll t = 1;
    cin >> t;
    while(t--)
        solve();
}