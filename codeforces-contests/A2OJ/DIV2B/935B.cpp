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
    ll n; cin >> n;
    string s; cin >> s;

    pll cd{0, 0};
    ll ans = 0;
    bool kd = s[0]=='U';
    bool last_kd;
    for(auto h : s)
    {
        last_kd = kd;
        if(h=='R') cd.ff++;
        else cd.ss++;

        if(cd.ss < cd.ff)
        {
            kd = false;
        }
        else if(cd.ss > cd.ff)
        {
            kd = true;
        }

        if(kd != last_kd) ans++;
    }

    cout << ans << '\n';
}
