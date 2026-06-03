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
    ll x, y, num = 0; cin >> x >> y;
    if(x>=y)
    {
        num = x*x;
        //cout << (x-1)+(x-y) << "<-\n";
        if(x&1)
            num -= (x-1)+(x-y);   
        else
            num -= (y-1); 
    }
    else
    {
        num = y*y;
        if(y&1)
            num -= (x-1);   
        else
            num -= (y-1)+(y-x); 
    }

    cout << num << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
