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
    ll n, k; cin >> n >> k;
    map<ll,ll> hs; queue<pll> xs;

    xs.push({n, 0});
    while(!xs.empty())
    {
        ll num = xs.front().ff, path = xs.front().ss; 
        xs.pop();
        if(hs.count(num))
            continue;
        
        hs[num] = path;
        xs.push({num/2, path+1});
        xs.push({ceil((double)num/2), path+1});
    }

    cout << (hs.count(k) ? hs[k] : -1) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
