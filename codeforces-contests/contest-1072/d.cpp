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

// dist do msb + 1 + numero de bits 1
// n!/k! * (n-k)!

map<pll, ll> vis;

void prep()
{
    for(ll n = 0; n < 30; ++n)
        for(ll k = 0; k < 30; ++k)
        {
            if(n < k) 
                vis[{n, k}] = 0;
            else if(k==0)
                vis[{n, k}] = 1;
            else
                vis[{n, k}] = vis[{n-1, k}] + vis[{n-1, k-1}];
        }

}

void solve()
{
    ll n, k; cin >> n >> k;
    ll ans = 0;

    bitset<32> bt(n); ll msb_pos = 31;
    for(; msb_pos >= 0 && bt[msb_pos]==0; --msb_pos);

    //cout << "-> " << msb_pos << '\n';
    if (msb_pos+1 > k)
        ++ans;

    for(ll i = 0; i <= msb_pos-1; ++i)
        for(ll j = 1; j <= i+1; ++j)
            if(i+j > k)
                ans += vis[{i, j-1}];

    cout << ans << '\n';
}

signed main()
{
    fio;
    prep();
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
