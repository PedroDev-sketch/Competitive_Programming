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

signed main()
{
    fio;
    
    ll n; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;

    ll ans = 0, seq = 0;
    ll buff = 0;
    for(auto x : xs)
    {
        if(x) {ans++; seq = max(seq, buff); if(buff) buff--;}
        else buff++;
    }
    seq = max(seq, buff);
    cout << (!seq ? max((ll)0, ans-1) : ans+seq) << '\n';
    
    return 0;
}