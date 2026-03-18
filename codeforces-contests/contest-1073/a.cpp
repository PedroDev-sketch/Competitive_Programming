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
    ll n; cin >> n;
    bool col = true;
    vector<pair<ll,bool>> xs(n); for(auto& [x, y] : xs) {cin >> x; y = col; col = !col;}
    sort(all(xs));
    col = xs[0].ss;
    for(ll i = 1; i < n; ++i)
    {
        if(xs[i].ss==col)
        {
            cout << "NO\n";
            return;
        }
        col = xs[i].ss;
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
