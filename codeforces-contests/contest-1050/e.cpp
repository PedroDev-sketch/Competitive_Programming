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
    ll n, k; cin >> n >> k;
    map<ll,ll> hs;
    vll xs(n); for(auto& x : xs) {cin >> x; hs[x]++;}
    ll ans = 0;
    for(auto [key, val] : hs)
    {
        if(val%k)
        {
            cout << "0\n";
            return;
        }
    }

    map<ll,ll> hs2 = hs;
    ll size = 0;
    for(ll i = 0; i < n; i++)
    {
        ll x = xs[i];
        size++;
        hs2[x]--;

        if(hs2[x]%(k-1))
        {
            size = 0;
            hs2 = hs;
            i-=2;
            i = max(i, 0LL);
        }

        else
        {
            ans += size;
        }
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
