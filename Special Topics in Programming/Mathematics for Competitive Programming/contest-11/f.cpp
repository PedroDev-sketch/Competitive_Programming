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
    vll ds;
    for(ll i = 2; i * i <= num; ++i)
    {
        if(num%i==0)
        {
            ds.eb(i);
            if(num/i!=i) ds.eb(num/i);
        }
    }
    return ds;
}

void solve()
{
    ll n; cin >> n;
    vll xs = divs(n);
    if(xs.size()<3)
    {
        cout << "NO\n";
        return;
    }

    sort(all(xs));

    for(ll i = 0; i < xs.size(); ++i)
        for(ll j = i+1; j < xs.size(); ++j)
        {
            ll num = xs[i] * xs[j];

            if(num > n)
            {
                cout << "NO\n";
                return;
            }

            ll rem = n/num;

            if(rem != xs[i] && rem != xs[j] && binary_search(all(xs), rem))
            {
                cout << "YES\n";
                cout << xs[i] << " " << xs[j] << " " << rem << '\n';
                return;
            } 
        }

        cout << "NO\n";
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
