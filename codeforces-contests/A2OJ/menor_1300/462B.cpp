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

signed main()
{
    fio;
    
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    map<char, ll> hs;
    for(auto x : s) hs[x]++;
    multiset<ll> xs;
    for(auto h : hs) xs.insert(h.second);
    ll ans = 0;
    for(auto it = xs.rbegin(); it!=xs.rend() && k; it++)
    {
        if(*it <= k)
        {
            ans += ((*it) * (*it));
            k -= *it;
        }
        else
        {
            ans += (k * k);
            k = 0;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
