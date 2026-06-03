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

void solve() {
    ll n;
    cin >> n; ll total = 4*n;
    vll xs(total); for(auto& x : xs) cin >> x;
    sort(all(xs));

    ll target = xs[0]*xs.back();
    
    for (ll i = 0; i < n; ++i) 
    {
        ll L = 2*i;                      
        ll R = total-1-2*i;
        
        if (xs[L] != xs[L+1] || xs[R] != xs[R-1] || (ll)xs[L] * xs[R] != target) 
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
