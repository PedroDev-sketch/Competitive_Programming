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
    ll n; cin >> n;
    vll xs(n); 
    for(auto& x : xs)
        cin >> x;
    
    vll pre;
    ll sum = 0, sub = 0, idx = 0;
    for(auto x : xs)
    {
        if(!idx)
        {
            ++idx;
            continue;
        }

        sum += abs(x);
        pre.eb(sum);  
        ++idx;
    }

    vll pos = pre;
    for(ll i = xs.size()-1; i >= 1; i--)
    {
        sub -= xs[i];
        pos[i-1] = sub;
    }

    /* cout << "-> ";
    for(auto p : pre)
        cout << p << " ";
    cout << '\n';

    cout << "-> ";
    for(auto p : pos)
        cout << p << " ";
    cout << '\n'; */

    ll ans = xs[0];
    for(ll i = 0; i < xs.size(); i++)
    {
        ll num = 0;
        if(i)
        {
            num = xs[0];
        }

        if(i>=2)
            num += pre[i-2];
        if(i < pos.size())
            num += pos[i];

        ans = max(ans, num);
    }

    cout << ans << '\n';
    
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
