#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

void solve()
{
    ll n, m; cin >> n >> m;
    vll a(n), b(m);
    for(auto& x : a) {cin >> x;} for(auto& x : b) cin >> x;

    if(n/2 < m)
    {
        cout << "NO\n";
        return;
    }

    sort(all(a)); sort(all(b));
    ll l = 0;
    for(auto x : b)
    {
        if(a[l] <= x)
            a[l] = -1;
        else
        {
            cout << "NO\n";
            return;
        }

        ++l;
    }

    /* for(auto x : a)
        cout << x << ' ';
    cout << '\n';

    for(auto x : b)
        cout << x << ' ';
    cout << '\n'; */

    for(auto& x : b)
    {
        while(l < n && a[l] < x)
            ++l;
        if(l < n && a[l] >= x)
            x = -1;
        ++l;
    }

    /* for(auto x : b)
        cout << x << ' ';
    cout << '\n'; */

    bool ans = true;
    for(auto x : b)
        if(x!=-1)
            ans = false;
    cout << (ans ? "YES\n" : "NO\n");
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
