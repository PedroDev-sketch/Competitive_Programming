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

const ll MOD = 998244353;

void solve()
{
    ll n, k; cin >> n >> k;

    ll max_sum = 0, limit = n - k + 1;
    vll maxidxs;

    for (ll i = 0; i < n; ++i) 
    {
        ll x; cin >> x;
        
        if (x >= limit) 
        {
            max_sum += x;
            maxidxs.eb(i); 
        }
    }

    ll comb = 1;
    for(ll i = 1; i < maxidxs.size(); ++i) 
    {
        ll diff = maxidxs[i] - maxidxs[i-1];
        comb = (comb *diff) % MOD;
    }

    cout << max_sum << " " << comb << "\n";
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
