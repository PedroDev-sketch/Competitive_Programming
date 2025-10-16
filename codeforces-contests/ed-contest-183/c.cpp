#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define MAXN (1e9 + 7)
#define ff first 
#define ss second 

void solve()
{
    ll n; cin >> n;
    ll a = 0, b = 0;
    string s; cin >> s;
    ll idx = 0;
    vll xs(n);
    for(auto x : s)
    {
        if(x=='a')a++;
        else b++;
        xs[idx] = a-b;
        idx++;
    }

    ll rm = xs[n-1];
    if(rm == n) cout << -1;
    else if(rm == 0) cout << 0;
    else
    {
        map<ll,ll> hs; 
        ll t = 0, seq = n;
        hs[t] = -1;
        for(ll i = 0; i < n; i++)
        {
            t+=(s[i]=='a'?1:-1);
            hs[t]=i;
            if(hs.count(t - rm))
                seq = min(seq, i - hs[t-rm]);
        }
        if(seq==n) cout << -1;
        else cout << seq;
    }
    cout << '\n';
}

signed main()
{
    fio;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}
