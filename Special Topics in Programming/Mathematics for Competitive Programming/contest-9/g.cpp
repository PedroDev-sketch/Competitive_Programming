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
    vll xs(2*n); for(auto& x : xs) cin >> x;
    ll swaps = 0;

    for (ll i = 0; i < 2 * n; i++) 
    {
        if (xs[i]==-1) continue;
        for (ll j = i+1; j < 2*n; j++) 
        {
            if (xs[j] == xs[i]) 
            {
                for (ll k = i + 1; k < j; k++) 
                    if (xs[k] != -1)
                        ++swaps;
                xs[i] = -1;
                xs[j] = -1;
                break;
            }
        }
    }

    //aceita code forces pf :(
    ll num = 0;
    cout << swaps << "\n";
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
