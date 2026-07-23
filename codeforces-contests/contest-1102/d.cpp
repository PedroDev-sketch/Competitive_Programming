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

constexpr ll MAXN = 1e5+21;

void solve() 
{
    ll n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    
    ll num = (1LL<<k)+1LL;

    ll one_s = 0, zero_s = 0;
    ll one_t = 0, zero_t = 0;
    ll one_z = 0, zero_z = 0;

    for(auto x : s)
        if(x=='1')
            ++one_s;
    zero_s = n - one_s;

    for(auto x : t)
        if(x=='1')
            ++one_t;
    zero_t = n - one_t;

    string z = "";
    for(ll i = 0; i < n; ++i)
        z += (s[i]==t[i] ? '0' : '1');

    for(auto x : z)
        if(x=='1')
            ++one_z;
    zero_z = n - one_z;


    cout << (one_s*zero_s*((num+1)/3) + (one_t*zero_t*((num+1)/3)) + (one_z*zero_z*(num/3))) << '\n';
}

signed main() {
    fio;
    ll t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}