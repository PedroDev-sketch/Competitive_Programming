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
    vll ps(n), as(n);
    vll ys(n, 0);
    deque<ll> xs;
    for(auto& x : ps) 
    {
        cin >> x; 
        if(ys.back()!=x)
            ys.eb(x);
    } 
    for(auto& x : as) 
    {
        cin >> x; 
        if(xs.empty() || xs.back()!=x)
            xs.push_back(x);
    }
    
    for(auto y : ys)
    {
        if(y == xs.front())
            xs.pop_front();

        if(xs.empty())
        {
            cout << "YES\n";
            return;
        }
    }
/* 
    while(!xs.empty())
    {
        cout << xs.front() << ' ';
        xs.pop_front();
    } cout << '\n'; */

    cout << "NO\n";
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
