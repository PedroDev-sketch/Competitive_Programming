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
    ll n, m; char x; cin >> n >> x >> m;
    ll a, b; char y; cin >> a >> y >> b;

    ll h = n-a-(b>m), min = (m + (b > m ? 60 : 0)) - b;
    if(h < 10)
        cout << '0';
    cout << h << ":";
    if(min < 10)
        cout << '0';
    cout << to_string(min) << '\n';
}

signed main()
{
    fio;
    solve();
}
