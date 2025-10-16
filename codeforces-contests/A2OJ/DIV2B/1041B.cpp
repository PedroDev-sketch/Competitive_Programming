#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define MAXN (1e9 + 7)
#define ff first 
#define ss second

signed main()
{
    fio;
    ll a, b, x, y; cin >> a >> b >> x >> y;
    ll g = gcd(x, y);
    x/=g; y/=g;
    cout << min(a/x, b/y) << '\n';
}
