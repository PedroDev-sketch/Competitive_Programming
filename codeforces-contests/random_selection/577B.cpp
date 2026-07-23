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

const ll MAXN = 1e6+7;

void solve()
{
    ll n, m, sum = 0; cin >> n >> m;
    vll xs(n); for(auto& x : xs) cin >> x; 
    
    if(n>=m)
    {
        cout << "YES\n";
        return;
    }

    vector<bool> st(m, false);
    for(auto x : xs)
    {
        vector<bool> nxt_st = st;

        x %= m;
        nxt_st[x] = true;

        for(ll i = 0; i < m; ++i)
            if(st[i])
                nxt_st[(x+i)%m] = true;

        st = nxt_st;

        if(st[0])
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
