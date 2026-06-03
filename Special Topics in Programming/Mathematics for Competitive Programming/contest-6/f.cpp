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
    ll num = (n*(n+1))/2;
    vvll xs;
    for(ll st = 0; st < n; ++st)
    {
        vll ys(n, 0);
        for(ll size = 0; st+size < n; ++size)
        {
            ys[st+size] = 1;
            xs.push_back(ys);
        }
    }


    vll ans(n, 0);
    for(auto x : xs)
        for(ll i = 0; i < n; ++i)
            ans[i] += x[i];

    cout << *max_element(all(ans)) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
