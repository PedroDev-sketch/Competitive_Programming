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
    ll n, q; cin >> n >> q;
    string s; cin >> s;

    vll cnt(n, 0);
    for(ll i = 1; i < n; ++i)
        cnt[i] += cnt[i-1] + (s[i]==s[i-1] ? 1 : 0);

    while(q--)
    {
        ll l, r, k; cin >> l >> r >> k;
        ll res = cnt[r-1] - cnt[l-1];
        cout << ((res+1)/2 <= k ? "YES" : "NO") << '\n';
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
