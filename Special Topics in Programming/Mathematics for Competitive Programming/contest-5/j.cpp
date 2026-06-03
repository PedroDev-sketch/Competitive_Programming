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
    vll xs(n); for(auto& x : xs) cin >> x;
    
    vll l(n), r(n);
    for(ll i = 0; i < n; ++i)
    {
        l[i] = i;
        while(l[i] > 0 && xs[l[i] - 1] % xs[i] == 0)
            l[i] = l[l[i]-1];
    }
    
    for(ll i = n-1; i >= 0; --i)
    {
        r[i] = i;
        while(r[i] < n - 1 && xs[r[i] + 1] % xs[i] == 0)
            r[i] = r[r[i]+1];
    }

    ll maxdiff = -1;
    set<ll> ans;

    for(ll i = 0; i < n; ++i)
    {
        ll diff = r[i] - l[i];
        if(diff > maxdiff)
        {
            maxdiff = diff;
            ans.clear();
            ans.insert(l[i]);
        }
        else if(diff==maxdiff)
            ans.insert(l[i]);
    }

    cout << ans.size() << ' ' << maxdiff << '\n';
    for(auto a : ans) cout << a+1 << ' ';
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
