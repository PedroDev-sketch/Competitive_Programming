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

void bracket_check(vll& ys, string s, ll idx, ll c)
{
    ll check = 0;
    if(c) for(auto p : s)
    {
        if(p == '(') check++;
        else check--;

        if(check < 0) {ys[idx] = -1; return;}
    }
    else for(ll i = (ll)s.size()-1; i >= 0; i--)
    {
        if(s[i] == '(') check--;
        else check++;

        if(check < 0) {ys[idx] = -1; return;}
    }
    ys[idx] = check;
}


signed main()
{
    fio;

    ll n;
    cin >> n;
    
    vector<string> xs(n);
    for(auto& x : xs) cin >> x;
    vll prefix(n, 0), suffix(n, 0);
    vll valid(1e6, 0);

    for(ll i = 0; i < n; i++)
    {
        bracket_check(prefix, xs[i], i, (ll)1);
        if(prefix[i] >= 0) valid[prefix[i]]++;
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        bracket_check(suffix, xs[i], i, (ll)0);
        if(suffix[i] >= 0) ans += valid[suffix[i]];
    }

    /* for(auto x : prefix) cout << x << " ";
    cout << '\n';
    for(auto x : suffix) cout << x << " ";
    cout << '\n'; */

    cout << ans << '\n';

    return 0;
}