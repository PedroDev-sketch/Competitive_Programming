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
    ll x, y; cin >> x >> y;
    ll sum = abs(x)+abs(y);
    ll num1 = sum, num2 = sum;
    if(x<0) num1 *= -1;
    if(y<0) num2 *= -1;

    if(num1<0)
        cout << num1 << ' ' << 0 << ' ' << 0 << ' ' << num2;
    else  
        cout << 0 << ' ' << num2 << ' ' << num1 << ' ' << 0;
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
