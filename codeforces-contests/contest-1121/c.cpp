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

const ll MOD = 998244353;

ll mod(ll a)
{
    a %= MOD;
    if(a < 0)
        return a + MOD;
    return a;
}

void solve()
{
    ll n; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;
    sort(all(xs), greater<>());

    if(n==1)
    {
        cout << "0\n";
        return;
    }

    vll ys{1, 1}, zs{0, mod(xs[0]-xs[1])};
    ll sum = mod(xs[0] + xs[1]);
    for(ll i = 3; i <= n; ++i)
    {
        ll size = ys.size(), prev_size = ys.back();

        ys.eb(mod(size*prev_size));

        ll op1 = mod(zs.back()*size);
        ll op2 = mod(sum*prev_size);
        ll op3 = mod(xs[i-1]*ys.back());
        ll op4 = mod(op2 - op3);
        
        zs.eb(mod(op1 + op4));
        sum += xs[i-1];
        sum = mod(sum);
    }
    cout << zs.back() << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
