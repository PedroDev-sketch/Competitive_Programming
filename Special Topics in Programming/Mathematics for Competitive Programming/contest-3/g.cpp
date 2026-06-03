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
    string s; cin >> s;
    ll bs = 0, ans = 0;
    ll mod = (1e9+7);
    for(ll i = s.length()-1; i>=0; --i)
    {
        char x = s[i];
        if(x=='b')
            bs = (bs+1) % mod;
        else
        {
            ans = (ans+bs)%mod;
            bs = (bs*2)%mod;
        }
    }

    cout << ans%mod << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
