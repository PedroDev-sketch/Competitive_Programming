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

vll divs(ll num)
{
    vll ds{num};
    for(ll i = 2; i * i <= num; ++i)
    {
        if(num%i==0)
        {
            ds.eb(i);
            if(num/i!=i)
                ds.eb(num/i);
        }
    }
    return ds;
}

void solve()
{
    ll n; cin >> n;
    vll xs(n); set<ll> ys; for(auto& x : xs) {cin >> x; ys.insert(x);}

    if(ys.size() == 1)
        cout << "0\n";
    else if(ys.size()==2)
    {
        auto it = ys.begin();
        ll a = *it;
        ll b = *next(it);
        ll diff = b-a;
        if(!(diff&1))
            cout << diff/2 << '\n';
        else cout << diff << '\n';
    }
    else if(ys.size()==3)
    {
        auto it = ys.begin();
        ll a = *it;
        ++it;
        ll b = *it;
        ++it;
        ll c = *it;

        if(b-a==c-b)
            cout << b-a << '\n';
        else cout << "-1\n";
    }
    else cout << "-1\n";
}

signed main()
{
    //fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
