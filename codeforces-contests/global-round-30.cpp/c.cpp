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
    ll n, m; cin >> n >> m;

    multiset<ll> as;
    vll a(n), b(m), c(m);
    for(auto& x : a) {cin >> x; as.insert(x);}
    for(auto& x : b) cin >> x;
    for(auto& x : c) cin >> x;

    vpll bc; vll zero;
    for(ll i = 0; i < m; i++)
    {
        if(c[i])
            bc.eb(b[i], c[i]);
        else
            zero.eb(b[i]);
    }

    sort(all(bc));

    /* cout << "preloop as-> ";
    for(auto x : as) cout << x << ' ';
    cout << '\n'; */

    ll ans = 0;
    if(!bc.empty()) for(auto [bi, ci] : bc)
    {
        //cout << "bi-> " << bi << '\n';
        auto it = as.lower_bound(bi);

        //cout << "It-> " << *it << '\n';
        if(it!=as.end())
        {
            //cout << "passedIt-> " << *it << '\n';
            ans++;
            ll num = max(*it, ci);
            as.erase(it);
            as.insert(num);
        }
        else break;

        /* cout << "as-> ";
        for(auto x : as) cout << x << ' ';
        cout << '\n'; */
    }

    /* cout << "outloop as-> ";
    for(auto x : as) cout << x << ' ';
        cout << '\n'; 

    cout << "prezero ans-> " << ans << '\n'; */
    if(!zero.empty())
    {
        sort(all(zero), greater<>());

        priority_queue<ll> xs;
        for(auto x : as) xs.emplace(x);
        ll sword = xs.top(); xs.pop();

        for(auto bi : zero)
        {
            if(bi > sword)
                continue;
            else
            {
                ans++;
                if(xs.empty()) break;
                sword = xs.top();
                xs.pop();
            }
        }
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



