#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair

signed main()
{   
    fio;

    ll n, k, x;
    cin >> n >> k >> x;

    vll xs(n);
    for(auto& p : xs) cin >> p;

    if(n/k > x)
    {
        cout << "-1\n";
        return 0;
    }

    vvll dp(n+1, vll(x+1, -LLONG_MAX));
    dp[0][x]=0;

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 0; j < x; j++)
        {
            for(ll p = 1; p <= k; p++)
            {
                if(i-p < 0) break;
                if(dp[i-p][j+1] == -LLONG_MAX) continue;
                dp[i][j] = max(dp[i][j], dp[i-p][j+1] + xs[i-1]);
            }
        }
    }

    ll ans = -LLONG_MAX;
    /* for(auto d : dp)
    {
        ans = max(ans, *max_element(all(d)));
    } */

    for (int i = n; i >= n-k+1; i--) 
    {
		ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
	}

    if(ans != -LLONG_MAX) cout << ans;
    else cout << -1;
    cout << '\n';

    return 0;
}