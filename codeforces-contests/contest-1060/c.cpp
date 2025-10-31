#include <bits/stdc++.h>
using namespace std;

using ll = int;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define MAXN (2e5+21)
#define ff first
#define ss second

vvll prime_divs(MAXN+1);

void sieve(ll num=MAXN)
{
    for(ll i = 2; i <= num; i++)
    {
        if(!prime_divs[i].empty())
            continue;
        for(ll j = i; j <= num; j+=i)    
            prime_divs[j].eb(i);
    }
}

void solve()
{
    ll n; cin >> n;
    vll a(n), b(n);

    ll odd = 0;
    for(auto& x : a) {cin >> x; odd += (x&1LL);}
    for(auto& x : b) cin >> x;

    if(odd <= n-2) {cout << "0\n";return;}

    map<ll,ll> divs;
    for(auto x : a)
    {
        for(auto y : prime_divs[x])
        {
            if(divs[y])
            {
                cout << "0\n";
                return;
            }
            divs[y]=1;
        }
    }
    
    for(auto x : a)
    {
        for(auto y : prime_divs[x])
            divs[y]=0;

        ll newx = x+1;
        for(auto y : prime_divs[newx])
        {
            if(divs[y])
            {
                cout << "1\n";
                return;
            }
        }

        for(auto y : prime_divs[x])
            divs[y]=1;
    }
    
    cout << "2\n";
}

signed main()
{
    fio;
    sieve();
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
