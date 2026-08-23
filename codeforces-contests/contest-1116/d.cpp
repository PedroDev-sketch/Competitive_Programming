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

const ll MOD = 998'244'353;
const ll MAXN = 1e6+10;
vll factorials(MAXN), inverse_factorials(MAXN);

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

ll mod_inv(ll num)
{
    return fast_pow(num, MOD-2);
}

void precompute()
{
    factorials[0] = 1;
    for(ll i = 1; i < MAXN; ++i)
        factorials[i] = i * factorials[i-1] % MOD;
    
    inverse_factorials[MAXN-1] = mod_inv(factorials[MAXN-1]);
    for(ll i = MAXN-2; i >= 0; --i)
        inverse_factorials[i] = (i+1) * inverse_factorials[i+1] % MOD;
}

void solve()
{
    ll n; cin >> n;
    string s; cin >> s;
    ll c0 = 0, b0 = 0, c1 = 0, b1 = 0;
    char last = '?';
    for(auto x : s)
    {
        if(x=='0')
            ++c0;
        else ++c1;

        if(x!=last && x=='0')
            ++b0;
        else if(x!=last && x=='1')
            ++b1;
        last = x;
    }

    ll p0 = 1, p1 = 1;
    if(c0>0) p0 = (factorials[c0 - 1] * inverse_factorials[b0 - 1] % MOD) * inverse_factorials[c0 - b0] % MOD;
    if(c1>0) p1 = (factorials[c1 - 1] * inverse_factorials[b1 - 1] % MOD) * inverse_factorials[c1 - b1] % MOD;
    cout << p0 * p1 % MOD << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    precompute();
    while (t--)
        solve();
}
