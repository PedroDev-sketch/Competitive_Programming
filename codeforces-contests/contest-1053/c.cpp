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
#define MAXN (1e9 + 7)
#define ff first
#define ss second

void solve()
{
    ll n; cin >> n;
    vll xs(2*n); for(auto& x : xs) cin >> x;
    vll d(n+1, 0), p(n+1, 0), peven(n, 0);

    for(ll i = 0; i < n; i++)
    {
        d[i+1] = d[i] + xs[2*n - i - 1] - xs[i];
        p[i+1] = p[i] + xs[2*i+1] - xs[2*i];
        if(i<n-1)
            peven[i+1] = peven[i] + xs[2*i+2] - xs[2*i+1];
        
    }
    for(ll k = 0; k < n; k++)
    {
        ll addon = (k&1) ? (peven[n - (k-1)/2 - 1] - peven[(k-1)/2]) : (p[n - k/2] - p[k/2]);
        cout << d[k]+addon << ' ';
    }
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
