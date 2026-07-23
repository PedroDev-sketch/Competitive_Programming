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
    ll n; cin >> n;
    vll hs(n), ws(n); for(auto& x : hs) cin >> x;

    vector<set<ll>> suffix(n), prefix(n);
    set<ll> p_buff, s_buff;
    for(ll i = 0; i < n; ++i)
    {
        p_buff.insert(hs[i]);
        prefix[i] = p_buff;
    }

    for(ll i = n-1; i >= 0; --i)
    {
        s_buff.insert(hs[i]);
        suffix[i] = s_buff;
    }

    for(ll i = 0; i < n; ++i)
    {
        
    }

    for(auto w : ws) cout << w << ' ';
    cout << '\n';
}

signed main() {
    fio;
    ll t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}