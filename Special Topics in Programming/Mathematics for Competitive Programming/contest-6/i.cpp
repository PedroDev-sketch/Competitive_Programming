#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second 

constexpr ll MAXN = 1e7+7;

vll spf(MAXN), ansa(MAXN), ansb(MAXN);

void sieve(ll num = MAXN)
{
    for(ll i = 2; i < MAXN; ++i)
        spf[i] = i;
    for(ll i = 2; i*i < MAXN; ++i)
        if(spf[i]==i)
            for(ll j = i; j < MAXN; j += i)
                if(spf[j] == j)
                    spf[j] = i;
}

void solve()
{
    ll n, m; cin >> n >> m;
    vll a(n), b(m);
    for(auto& x : a)
    {
        cin >> x;
        ll temp = x;
        while(temp>1)
        {
            ansa[spf[temp]]++;
            temp /= spf[temp];
        }
    }
    
    for(auto& x : b)
    {
        cin >> x;
        ll temp = x;
        while(temp>1)
        {
            ansb[spf[temp]]++;
            temp /= spf[temp];
        }
    }

    for(ll i = 2; i < MAXN; ++i)
    {
        ll num = min(ansa[i], ansb[i]);
        ansa[i] = num;
        ansb[i] = num;
    }

    for(auto& x : a)
    {
        ll temp = x, val = 1;
        while(temp > 1)
        {
            ll p = spf[temp];
            if(ansa[p] > 0)
                ansa[p]--;
            else
                val *= p;

            temp /= p;
        }
        x = val;
    }

    for(auto& x : b)
    {
        ll temp = x, val = 1;
        while(temp > 1)
        {
            ll p = spf[temp];
            if(ansb[p] > 0)
                ansb[p]--;
            else
                val *= p;

            temp /= p;
        }
        x = val;
    }

    cout << n << " " << m << '\n';
    for(auto x : a)
        cout << x << " ";
    cout << '\n';
    for(auto x : b)
        cout << x << " ";
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    sieve();
    while (t--)
        solve();
}
