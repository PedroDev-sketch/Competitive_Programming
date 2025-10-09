#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll n, k, X; cin >> n >> k >> X;
    vll xs(n); 
    ll ans = 0;
    for(auto& x : xs) cin >> x;
    sort(all(xs), greater<>()); 
    
    //cout << "debug1\n";
    for(auto& x : xs) 
    {
        cin >> x;
        ll diff = x/X;
        ll val = 0;
        if(k >= diff)
        {
            k -= diff;
            val = x%X;
            x = val;
        }
    }
    //cout << "debug2\n";

    sort(all(xs), greater<>());
    for(auto& x : xs)
    {
        if(k>0)
        {
            ll diff = x/X;
            if(diff > k)
            {
                x = max(x - k*X, (ll)0);
                k=0;
            }
            else
            {
                k -= max(diff, (ll)1);
                x=0;
            }
        }

        ans += x;
    }
    //cout << "debug3\n";


    cout << ans << '\n';
}

signed main()
{
    fio;
    //ll t; cin >> t;
    solve();
    return 0;
}