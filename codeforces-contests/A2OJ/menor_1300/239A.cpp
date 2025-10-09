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
   
    ll y, k, n;
    cin >> y >> k >> n;

    ll flag = false;
    for(ll i = k; i <= n; i+=k)
    {
        ll num = i - y;
        if(num > 0 && num <= n)
        {
            flag = true;
            cout << num << " ";
        }
    }
    
    if(!flag) cout << -1;
    cout << '\n';
    
    return 0;
}