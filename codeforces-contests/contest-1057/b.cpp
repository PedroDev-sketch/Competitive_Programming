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
#define MAXN (1e9 + 7)
#define ff first
#define ss second

void solve()
{
    ll x, y, z;
    cin >> x >> y >> z;
    bitset<64> btx(x), bty(y), btz(z);
    bool ans = true;
    for(ll i = 0; i < 64 && ans; i++)
    {
        ll num = (btx[i]==1) + (bty[i]==1) + (btz[i]==1);  
        if(num != 0 && num!= 1 && num!=3) ans = false;
    }

    if(!ans)
        cout << "NO\n";
    else cout << "YES\n";
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
