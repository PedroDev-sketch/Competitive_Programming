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
    ll k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
    ll rate = 0, ans = 0;
    ll upbound = r2;
    ll num = pow(k, rate);
    while(true)
    {
        if(num > r2/l1) break;

        ll bnumy = r2 / num;
        bnumy = min(bnumy, r1);

        ll snumy = l2 / num;
        if(l2%num) snumy++;
        snumy = max(snumy, l1);
        if(bnumy >= snumy) {ans += bnumy - snumy + 1; /* cout << "-> " << snumy << " - " << bnumy << '\n'; */}
        
        rate++;
        num = pow(k, rate);
    }
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t; cin >> t;
    while(t--) solve();
}
