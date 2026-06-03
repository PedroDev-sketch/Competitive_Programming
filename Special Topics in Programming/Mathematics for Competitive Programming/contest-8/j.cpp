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
    ll n, k, x; cin >> n >> k >> x;
    ll neg_cnt = 0, idx = 0; priority_queue<pll, vpll, greater<>> ys;
    vll xs(n); for(auto& x : xs) {cin >> x; neg_cnt += (x<0); ys.push({abs(x), idx}); ++idx;}

    while(k && !ys.empty())
    {
        idx = ys.top().ss;
        ys.pop();

        if(neg_cnt&1)
        {
            if(xs[idx] < 0)
                xs[idx] -= x;
            else
                xs[idx] += x;
        }
        else
        {
            if(xs[idx]<0)
            {
                xs[idx] += x;
                if(xs[idx]>=0)
                    --neg_cnt;
            }
            else
            {
                xs[idx] -= x;
                if(xs[idx]<0)
                    ++neg_cnt;
            }
        }

        k--;
        ys.push({abs(xs[idx]), idx});
    }

    for(auto x : xs) cout << x << ' ';
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
