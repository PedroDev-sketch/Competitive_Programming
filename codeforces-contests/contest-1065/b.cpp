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
    vll xs(n); for(auto& x : xs) cin >> x;

    multiset<ll> fdiffs;
    ll sum = 0;
    for(ll i = 1; i < n; i++)
    {
        if(xs[i]!=-1 && xs[i-1]!=1)
        {
            fdiffs.emplace(xs[i]-xs[i-1]);
            sum += xs[i]-xs[i-1];
        }
    }

    if(xs[0]==-1 && xs[n-1]==-1)
    {
        xs[0] = 0;
        xs[n-1] = 0;
        sum = 0;
    }
    else if(xs[n-1]==-1)
    {
        xs[n-1] = xs[0];
        sum = 0;
    }
    else if(xs[0]==-1)
    {
        xs[0] = xs[n-1];
        sum = 0;
    }

    for(ll i = 1; i < n-1; i++)
    {
        if(xs[i]==-1)
        {
            xs[i] = 0;
        }
    }

    sum = 0;
    for(ll i = 1; i < n; i++)
    {
        sum += xs[i] - xs[i-1];
    }

    cout << abs(sum) << '\n';
    for(auto x : xs) cout << x << ' ';
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
