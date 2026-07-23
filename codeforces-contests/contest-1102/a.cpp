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
    vll xs(n); map<ll,ll> hs;
    for(auto& x : xs) {cin >> x; ++hs[x];}

    sort(all(xs));
    for(ll i = 1; i < n; ++i)
    {
        for(ll j = 0; j < i; ++j)
        {
            map<ll,ll> hs2;

            ll x = xs[i], y = xs[j];
            ll savex = x, savey = y;

            ++hs2[x]; ++hs2[y];
            for(ll k = 2; k < n; ++k)
            {
                if(y==0)
                    break;
                ll z = x%y;
                ++hs2[z];

                x = y;
                y = z;
            }

            if(hs2==hs)
            {
                cout << savex << ' ' << savey << '\n';
                return;
            }
        }
    }

    cout << "-1\n";
}

signed main() {
    fio;
    ll t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}