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

set<ll> divs(ll n)
{
    set<ll> ds;
    for(ll i=1;i*i<=n;++i)
        if(n%i==0)
        {
            ds.insert(i);
            if(i!=n/i) ds.insert(n/i);
        }
    return ds;
}

void solve()
{
    ll n, k; cin >> n >> k;
    vector<string> xs(k);
    for(auto& x : xs) cin >> x;

    set<ll> ds = divs(n);

    vll hs(n, 0);
    for(ll i = 0; i < n; ++i)
        for(ll j = 0; j < k; ++j)
            hs[i] |= (1LL<<(xs[j][i] - 97));

    for(auto d : ds)
    {
        string ans = "";
        for(ll i = 0; i < d; ++i)
        {
            ll num = hs[i];
            for(ll j = d; i+j < n; j+=d)
                num &= hs[i+j];
            
            if(num)
            {
                char c;
                for(ll k = 0; k < 26; ++k)
                    if(num&(1<<k))
                        c = k+97;
                ans += c;
            }
        }

        if(ans.size()==d)
        {
            string save = ans;
            while(ans.size()<n)
                ans += save;

            cout << ans << '\n';
            return;
        }
    }
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
