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
    vll xs(n);
    ll ones = 0, twos = 0;
    for(auto& x : xs)
    {
        cin >> x;
        if(x==1) ++ones;
        else ++twos;
    }
    if(twos)
    {
        cout << "2 ";
        --twos;
    }
    if(ones)
    {
        cout << "1 ";
        --ones;
    }
    while(twos)
    {
        cout << "2 ";
        --twos;
    }
    while(ones)
    {
        cout << "1 ";
        --ones;
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
