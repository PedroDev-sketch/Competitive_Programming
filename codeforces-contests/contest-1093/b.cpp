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

void solve()
{
    ll n, m; cin >> n >> m;
    vll xs(n); for(auto& x : xs) cin >> x;
    ll span = 0, last = -1;
    for(ll i = 0; i < n; ++i)
    {
        if(xs[i]==last)
            ++span;
        else
            span = 1;
        
        if(span >= m)
        {
            cout << "NO\n";
            return;
        }
        
        last = xs[i];
    }

    cout << "YES\n";
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
