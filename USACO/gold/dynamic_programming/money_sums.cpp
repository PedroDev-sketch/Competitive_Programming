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

const ll MAXN = 1e5+21;

void solve()
{
    ll n; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;
    
    vll dp(MAXN+1, 0); dp[0] = 1;
    priority_queue<ll, vll, greater<ll>> pq;

    for(auto x : xs)
        per(i, MAXN, 0)
        {
            if(i-x < 0)
                break;

            if(!dp[i-x] || dp[i])
                continue;
            
            dp[i] = 1;
            pq.push(i);
        }

    if(pq.top()==0)
        pq.pop();
    cout << pq.size() << '\n';
    while(!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
