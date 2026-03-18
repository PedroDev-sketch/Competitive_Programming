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
#define MAXN (1e9 + 7)
#define ff first
#define ss second

void solve()
{
    ll n; cin >> n;

    ll p = 0, q = 0;
    for(ll i = 2; i * i * i <= n; i++)
    {
        if(n%i) continue;

        ll num = n/i;
        if(num%i==0)
        {
            p = i;
            q = n/(i*i);
        }
        else
        {
            q = i;
            p = sqrt(n/i);
        }
        
        cout << p << " " << q << '\n';
        return;
    }
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
