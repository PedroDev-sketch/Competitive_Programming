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
    ll n, ans = 0, sum = 0; cin >> n;
    vll xs(n); stack<pll> ys;
    for(auto& x : xs) cin >> x;
    for(ll i = n-1; i >= 0; --i)
    {
        ll num = xs[i];
        while(!ys.empty() && ys.top().ff==num+1)
        {
            sum -= n - ys.top().ss;
            ys.pop();
        }
        ys.push({num, i});
        sum += n-i;
        ans += sum;
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
