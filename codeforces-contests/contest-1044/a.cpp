#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vvll = vector<vll>;
using vpll = vector<pll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vll xs(n);
        for(auto& x : xs) cin >> x;
        
        bool ans = false;
        set<ll> ys;
        ll sz = ys.size();
        for(int i = 0; i < n && !ans; i++)
        {
            ys.insert(xs[i]);
            if(ys.size() == sz) ans = true;
            sz = ys.size();
        }

        cout << (ans ? "Yes" : "No") << '\n';
    }

    return 0;
}