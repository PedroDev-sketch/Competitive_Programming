#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vvll = vector<vll>;
using vpll = vector<pll>;

#define rep(i, a, b) for(ll i = (ll) a; i < (ll) b; i++);
#define per(i, a, b) for(ll i = (ll) a; i >= (ll) b; i--);
#define fio cin.tie(0)->sync_with_stdio(0)

signed main()
{
    fio;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;

        vll xs(n);
        for(auto& x : xs) cin >> x;

        if(k%2)
        {
            for(auto& x : xs)
            {
                if(x%2) x += k;
                //else x += k*2;
            }
        }
        else
        {
            for(auto& x : xs)
            {
                x += k * (x%(k+1));
            }
        }

        for(auto x : xs) cout << x << " ";
        cout << "\n";
    }

    return 0;
}