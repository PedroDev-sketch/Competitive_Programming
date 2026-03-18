#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define eb emplace_back
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll n, t; cin >> n >> t;
    bool ans = false;

    vll xs(n-1);
    for(auto& x : xs) cin >> x;

    if(t==1)
        ans = true;

    ll i = 0;
    while(i < n-1)
    {
        i = xs[i] + i;
        if(i+1 == t)
            ans = true;
    }

    cout << (ans ? "YES" : "NO") << '\n';
}

signed main()
{
    fio;
    ll t=1; //cin >> t;
    while(t--) solve();
}
