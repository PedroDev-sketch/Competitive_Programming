#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

const ll MAXN = 1e6+10;

void solve()
{
    ll n, m; cin >> n >> m;

    ll ans = 2e18;
    for(ll i = 2; i*i <= n; ++i)
    {
        if(n%i==0)
        {
            ll cnt = 0;
            while(n%i==0)
            {
                ++cnt;
                n /= i;
            }

            ll curr_ans = 0, temp_m = m;
            while(temp_m >= i)
            {
                curr_ans += temp_m / i;
                temp_m /= i;
            }
            
            ans = min(ans, curr_ans/cnt);
        }
    }

    if(n > 1) 
    {
        ll curr_ans = 0, temp_m = m;
        while(temp_m >= n)
        {
            curr_ans += temp_m / n;
            temp_m /= n;
        }
        
        ans = min(ans, curr_ans);
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while(t--)
        solve();
}