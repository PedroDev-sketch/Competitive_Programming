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
    vector<double> xs(n); for(auto& x : xs) cin >> x;
    sort(all(xs), greater<>());

    double ans = 0;
    for(ll i = 1; i <= n; ++i)
    {
        double prob = 0;
        for(ll j = 0; j < i; ++j)
        {
            double currprob = xs[j];
            for(ll k = 0; k < i; ++k)
                if(j!=k)
                    currprob *= (1.0 - xs[k]);
            prob += currprob;
        }
        ans = max(ans, prob);
    }

    cout << fixed << setprecision(12) << ans << "\n";
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
