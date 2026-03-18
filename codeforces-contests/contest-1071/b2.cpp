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
    ll n, sum = 0, val = 0; cin >> n;
    vll xs(n); for(auto& x : xs) {cin >> x; if(val) sum += abs(x - val); val = x;}
    
    ll ans = sum;
    for(ll i = 0; i < n; i++)
    {
        ll newdist = 0;
        if(!i)
            newdist = sum - abs(xs[i+1] - xs[i]);

        else if(i==n-1)
            newdist = sum - abs(xs[i] - xs[i-1]);

        else
        {
            ll sub = abs(xs[i] - xs[i-1]);
            ll diff = abs(xs[i+1] - xs[i]);
            newdist = sum - sub - diff + abs(xs[i+1] - xs[i-1]);
        }

        ans = min(ans, newdist);
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
