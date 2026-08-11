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
    vll stability(n); for(auto& x : stability) cin >> x;
    vvll xs(n, vll(m));
    rep(i, 0, n)
        for(auto& x : xs[i])
            cin >> x;

    ll ans = m, sum = 0;
    priority_queue<ll, vll, greater<ll>> pq;
    per(i, n-1, 0)
    {
        rep(j, 0, m)
        {
            ll num = xs[i][j];
            if(ans==1) continue;

            if(pq.size() < ans-1)
            {
                pq.push(num);
                sum += num;
            }
            else if(!pq.empty() && num > pq.top())
            {
                sum += num - pq.top();
                pq.pop();
                pq.push(num);
            }
        }

        while(!pq.empty() && sum >= stability[i])
        {
            ans = min((ll)pq.size(), ans);
            while(pq.size() > ans-1)
            {
                sum -= pq.top();
                pq.pop();
            }
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
