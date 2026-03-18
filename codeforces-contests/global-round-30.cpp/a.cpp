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
    ll l = 1e10, r = -1e10;
    vll xs(n); for(auto& x : xs) 
    {
        cin >> x;
        l = min(l, x);
        r = max(r, x);
    }
    ll x; cin >> x;

    if(x <= r && x >= l)
        cout << "YES";
    else cout << "NO";
    cout << '\n';
    return;
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}



