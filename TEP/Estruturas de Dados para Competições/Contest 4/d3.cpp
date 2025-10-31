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
    ll n, m; cin >> n >> m;
    map<ll, ll> hs;
    ll sum = 0;
    vll xs(n); for(auto& x : xs) {cin >> x; hs[x] += x; sum += x;}
    vpll ys; for(auto h : hs) ys.eb(h);
    ll size = ys.size();

    ll ans = sum;

    if(hs.count(m-1))
    {
        ll buff = 0, num = m;
        ll idx = size-1;

        while(idx >= 0 && ys[idx].ff == num-1)
        {
            buff += ys[idx].ss;
            num--;
            idx--;
        }

        //cout << "1 -> " << buff << '\n';

        if(idx && hs.count(0))
        {
            idx = 0, num = -1; 
            while(idx < size && ys[idx].ff == num+1)
            {
                buff += ys[idx].ss;
                num++;
                idx++;
            }
        }

        //cout << "2 -> " << buff << '\n';

        ans = min(ans, sum - buff);
    }

    ll idx = 0, num = ys[idx].ff-1;
    while(idx < size)
    {
        ll buff = 0;
        while(idx < size && ys[idx].ff == num+1)
        {
            buff += ys[idx].ss;
            num++;
            idx++;
        }

        num = ys[idx].ff-1;

        //cout << "3 -> " << buff << '\n';
        ans = min(ans, sum - buff);
    }

    //cout << sum << '\n';
    cout << max(ans, 0LL) << '\n';
}

signed main()
{
    //fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
