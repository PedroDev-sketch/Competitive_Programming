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
    ll n, idx = 0; cin >> n;
    vll xs(2*n);
    vll odd, even;
    for(auto& x : xs)
    {
        cin >> x;
        if(x&1)
            odd.eb(idx);
        else
            even.eb(idx);
        ++idx;
    }

    if(odd.size()&1)
    {
        auto it = prev(odd.end());
        odd.erase(it);
        auto it2 = prev(even.end());
        even.erase(it2);
    }
    else if(odd.size()>=2)
    {
        auto it = prev(odd.end());
        auto it2 = prev(it);
        odd.erase(it);
        odd.erase(it2);
    }
    else
    {
        auto it = prev(even.end());
        auto it2 = prev(it);
        even.erase(it);
        even.erase(it2);
    }

    for(ll i = 1; i < odd.size(); i+=2)
        cout << odd[i]+1 << " " << odd[i-1]+1 << '\n';
    for(ll i = 1; i < even.size(); i+=2)
        cout << even[i]+1 << " " << even[i-1]+1 << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
