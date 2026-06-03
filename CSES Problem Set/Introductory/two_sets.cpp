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
    ll num = n*(n+1)/2;
    if(num&1)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    ll sum = 0; vll xs, ys;
    for(ll i = n; i >= 1; --i)
    {
        if(sum+i <= num/2)
        {
            sum += i;
            xs.eb(i);
        } else ys.eb(i);
    }

    cout << xs.size() << '\n';
    for(auto x : xs) cout << x << ' ';
    cout << '\n';

    cout << ys.size() << '\n';
    for(auto x : ys) cout << x << ' ';
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
