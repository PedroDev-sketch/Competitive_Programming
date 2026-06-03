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
    vll xs(n); for(auto& x : xs) cin >> x;
    vector<multiset<pll>> ys(n);

    ll q; cin >> q;
    ll lastnum = -1;
    ll xq = -1;

    for(ll idx = 0; idx < q; idx++)
    {
        ll t; cin >> t;
        if(t==1)
        {
            ll x; cin >> x;
            lastnum = idx;
            xq = x;
        }
        else if(t==2)
        {
            ll i, x; cin >> i >> x;
            ys[i-1].emplace(lastnum, x);
        }
        else
        {
            ll i; cin >> i;

            ll sum = 0;
            if(!ys[i-1].empty())
            {
                auto it = ys[i-1].lower_bound(mp(lastnum, -1e9));
                for(; it != ys[i-1].end(); it++)
                {
                    if(it->ff >= lastnum) 
                        sum += it->ss;
                    else break;
                }
            }

            if(lastnum==-1)
                cout << xs[i-1]+sum << '\n';
            else 
            {
                cout << xq+sum << '\n';
            }
        }
    }
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
