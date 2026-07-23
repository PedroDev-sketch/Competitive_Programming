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

const ll MOD = 1e9+7;

ll fast_pow(ll base, ll exp)
{
    ll res = 1;
    while(exp > 0)
    {
        if(exp&1)
        {
            res *= base;
            res %= MOD;
        }
        base *= base;
        base %= MOD;
        exp >>= 1;
    }
    return res;
}

void solve()
{
    ll n, cnt_neg = 0, cnt_pos = 0; cin >> n;
    vll xs(n), pos; 
    for(auto& x : xs)
    {
        cin >> x;
        if(x < 0)
            ++cnt_neg;
        else if(pos.empty() || pos.back() != x)
            pos.eb(x);
    }

    cnt_pos = xs.size() - cnt_neg;
    ll x = fast_pow(2LL, cnt_pos - pos.size());
    if(cnt_neg==0)
    {
        cout << x << '\n';
        return;
    }

    ll p = 0;
    for(ll i = 1; i < pos.size(); ++i)
        if(pos[i]==pos[i-1]+1)
            ++p;

    ll y = fast_pow(2, cnt_neg - 1);
    cout << ((x*y % MOD) + ((x*p % MOD)*y % MOD)) % MOD << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
