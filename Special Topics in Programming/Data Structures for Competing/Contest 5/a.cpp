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
    ll n, k; cin >> n >> k;

    deque<ll> ys;
    vll xs(n); for(auto& x : xs){ cin >> x; ys.push_back(x);}

    for(ll i = 0; i < k; i++)
    {
        ys.pop_front();
        ys.push_back(0);
    }

    for(auto y : ys) cout << y << ' ';
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
