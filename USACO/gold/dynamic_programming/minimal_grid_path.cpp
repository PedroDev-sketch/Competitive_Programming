#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

const ll MOD = 1e9+7;

void solve()
{
    ll n; cin >> n;
    vector<string> grid(n);
    for(auto& x : grid) cin >> x;

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    dp[0][0] = true;
    
    string ans = "";
    ans += grid[0][0];
    
    for (ll d = 1; d <= 2 * n - 2; ++d) 
    {
        char min_char = 'a'; 
        
        rep(i, 0, d+1) 
        {
            ll j = d - i;
            if (i >= n || j >= n)
                continue; 
            
            bool reachable = false;
            if (i > 0 && dp[i-1][j]) reachable = true;
            if (j > 0 && dp[i][j-1]) reachable = true;
            
            if (reachable) 
                min_char = min(min_char, grid[i][j]);
        }
        
        rep(i, 0, d+1)
        {
            ll j = d - i;
            
            if (i >= n || j >= n)
                continue;
            
            bool reachable = false;
            if (i > 0 && dp[i-1][j]) reachable = true;
            if (j > 0 && dp[i][j-1]) reachable = true;
            
            if (reachable && grid[i][j] == min_char) {
                dp[i][j] = true;
            }
        }
        
        ans += min_char;
    }
    
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
