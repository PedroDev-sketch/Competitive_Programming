#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

void solve()
{
    ll n, m; cin >> n >> m;
    vll xs(n); for(auto& x : xs) cin >> x;
    priority_queue<ll> pq;

    if(n==1)
    {
        cout << xs[0] << '\n';
        return;
    }

    ll sum = 0;
    rep(i, 0, m-1)
    {
        pq.push(xs[i]);
        sum += xs[i];
    }

    ll ans = -1e12;
    rep(i, m-1, n)
    {
        ans = max(ans, m*xs[i] - sum);

        if(xs[i] < pq.top())
        {
            sum -= pq.top();
            sum += xs[i];
            pq.pop();
            pq.push(xs[i]);
        }
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
