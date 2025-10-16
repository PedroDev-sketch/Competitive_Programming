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
//#define swap(a, b) {ll temp = b; b = a; a = temp;}

signed main()
{
    fio;
    ll n; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;

    for(ll i = 0; i < n/2; i++)
        if((i+1)%2) 
            swap(xs[i], xs[n-i-1]);
    
    for(auto x : xs) cout << x << ' ';
    cout << '\n';

    return 0;
}
