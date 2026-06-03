#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll n, s; cin >> n >> s;
    vll xs(n), ys(n);
    for(auto& x : xs) cin >> x;
    for(auto& x : ys) cin >> x;

    if(xs[0]==0 || (xs[s-1]==0 && ys[s-1]==0))
    {
        cout << "NO\n";
        return;
    }

    if(xs[s-1]==1)
    {
        cout << "YES\n";
        return;
    }

    bool check = false;
    for(ll i = s; i < n; i++)
        if(xs[i]==1 && ys[i]==1)
            check = true;

    if(ys[s-1]==1 && check)
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

signed main()
{
    fio;
    ll t=1; //cin >> t;
    while(t--) solve();
}
