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
    ll n, x; cin >> n >> x;
    n%=6; 
    for (int i = n; i >= 1; --i) 
    {
        if (i%2) 
        {
            if (x == 0) x = 1;
            else if (x == 1) x = 0;
        } 
        else 
        {
            if (x == 1) x = 2;
            else if (x == 2) x = 1;
        }
    }
    cout << x << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
