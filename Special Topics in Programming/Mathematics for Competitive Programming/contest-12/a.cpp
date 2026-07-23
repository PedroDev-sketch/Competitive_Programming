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
    ll n, cnt = 0; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;

    for(ll i = 1; i < n; ++i)
    {
        ll num1 = max(xs[i], xs[i-1]), num2 = min(xs[i], xs[i-1]);
        while(num2*2<num1)
        {
            num2*=2;
            ++cnt;
        }
    }

    cout << cnt << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
