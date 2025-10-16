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
#define mp make_pair
#define MAXN (1e9 + 7)
#define ff first 
#define ss second

signed main()
{
    fio;
    ll n, l, r;
    cin >> n >> l >> r;
    
    ll low = 0, high = 0;
    ll low_rate = 2, high_rate = 1;
    for(ll i = 0; i < n; i++)
    {
        if(i <= n - l)
            low++;
        else
        {
            low += low_rate;
            low_rate*=2;
        }

        if(i < r-1)
        {
            high += high_rate;
            high_rate *= 2;
        }
        else high += high_rate;
    }

    cout << low << " " << high << '\n';

    return 0;
}
