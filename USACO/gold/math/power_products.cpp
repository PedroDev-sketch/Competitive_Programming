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

const ll MAXN = 1e5+11;
vll spf(MAXN);
void sieve(ll n = MAXN)
{
    for(ll i = 1; i < n; ++i)
        spf[i] = i;
    for(ll i = 2; i < n; ++i)
        if(spf[i]==i)
            for(ll j = i*i; j < n; j += i)
                if(spf[j]==j)
                    spf[j] = i;
}

ll fast_pow(ll base, ll exp)
{
    ll res = 1;
    while(exp > 0)
    {
        if(exp&1)
            res *= base;
        base *= base;
        exp >>= 1;

        if(res > MAXN) return MAXN+1;
    }
    return res;
}

void solve()
{
    ll n, k, ans = 0; cin >> n >> k;
    map<ll, ll> hs;
    vll xs(n); for(auto& x : xs) cin >> x;
    
    for(auto x : xs)
    {
        ll num = x, c_num = 1, val = 1;
        pll ps{-1, -1};

        while(num > 1)
        {
            if(spf[num] != ps.ff)
            {
                if(ps.ff!=-1)
                {
                    ps.ss %= k;
                    if(ps.ss) 
                    {
                        val *= fast_pow(ps.ff, ps.ss);
                        ll comp = k - ps.ss;
                        c_num *= fast_pow(ps.ff, comp);
                    }
                }

                ps.ff = spf[num];
                ps.ss = 0;
            }

            num /= spf[num];
            ++ps.ss;
        }
        
        if(ps.ff!=-1)
        {
            ps.ss %= k;
            if(ps.ss) 
            {
                val *= fast_pow(ps.ff, ps.ss);
                ll comp = k - ps.ss;
                c_num *= fast_pow(ps.ff, comp);
            }
        }

        if(c_num < MAXN && hs.count(c_num))
            ans += hs[c_num];
        
        if(val < MAXN)
            ++hs[val];
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    sieve();
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
