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
    ll ans = 1, val = -1, cnt = 0;
    while(n > 1)
    {
        if(spf[n]!=val)
        {
            ans *= cnt+1;
            val = spf[n];
            cnt = 0;
        }
        n /= spf[n];
        ++cnt;
    }
    if(cnt)
        ans *= cnt+1;
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
