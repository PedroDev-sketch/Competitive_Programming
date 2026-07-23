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

vll spf(1e6+10, 0);
void sieve(ll num = 1e6+10)
{
    for(ll i = 1; i < num; ++i)
        spf[i] = i;
    for(ll i = 2; i * i < num; ++i)
        if(spf[i]==i)
            for(ll j = i*i; j < num; j+=i)
                if(spf[j]==j)
                    spf[j] = i;
}

void solve()
{
    ll n; cin >> n;

    vpll xs;
    ll val = -1, cnt = 0;
    while(n > 1)
    {
        if(spf[n]!=val)
        {
            if(val!=-1)
                xs.eb(val, cnt);
            val = spf[n];
            cnt = 1;
        }
        n /= spf[n];
        cnt *= val;
    }
    if(cnt)
        xs.eb(val, cnt);
    
    ll ans = 1;
    for(auto [x, y] : xs)
    {
        //cout << "-> " << x << ' ' << y << '\n';
        if(y==x)
            ans *= x-1;
        else ans *= y - y/x;
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    sieve();
    cin >> t;
    while (t--)
        solve();
}
