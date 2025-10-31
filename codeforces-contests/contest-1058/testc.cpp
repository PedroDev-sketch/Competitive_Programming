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

void solve()
{
    ll n; cin >> n;

    for(ll i = 0; i < 1'000'000'000; i++)
    {
        
                bitset<64> x(i);
                string strx = x.to_string();

                ll k = 0;
                for(; k < strx.size() && strx[k]=='0'; k++);
                strx = strx.substr(k, strx.size() - k);
                
                string strfx = strx;
                reverse(all(strfx));

                /* cout << k << '\n';
                cout << x << '\n';
                cout << strx << '\n' << strfx << '\n'; */

                bitset<64> fx(strx);
                ll num = fx.to_ullong();

                if((i xor num) != n) continue;

                cout << i << " " << num << '\n';
                return;
    }
}

signed main()
{
    fio;
    ll t=1; //cin >> t;
    while(t--) solve();
}
