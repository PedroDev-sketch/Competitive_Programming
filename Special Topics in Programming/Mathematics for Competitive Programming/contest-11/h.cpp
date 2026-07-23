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

bool flag = false;

void bin_find(ll l, ll r, ll& s, ll& ans)
{
    if(l > r || l==r)
        return;

    ll m = (l+r)/2, sum = 0;
    string str_m = to_string(m);
    for(auto x : str_m)
        sum += (x - '0');
    ll res = m - sum;

    //cout << "-> " << m << " : " << res << '\n';

    if(res < s)
        bin_find(m+1, r, s, ans);
    else {ans = min(ans, m); bin_find(l, m, s, ans); flag = true;}
}

void solve()
{
    ll n, s; cin >> n >> s;
    ll ans = n; bin_find(1LL, n+1, s, ans);
    cout << (!flag ? 0 : n - ans + 1) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
