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
    vll a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    vll count(n + 1, 0);
    ll total_valid = 0;
    ll ans = 0;

    for (ll i = 0; i < n; ++i) 
    {
        count[0]++;
        total_valid++;

        if (a[i] == b[i]) 
        {
            ll x = a[i];
            count[x] += count[x - 1];
            count[x - 1] = 0;
        } 
        else 
        {
            total_valid -= count[a[i] - 1];
            count[a[i] - 1] = 0;
            
            if (a[i] != b[i]) 
            {
                total_valid -= count[b[i] - 1];
                count[b[i] - 1] = 0;
            }
        }
        
        ans += total_valid;
    }
    
    cout << ans << '\n';
}

signed main() {
    fio;
    ll t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}