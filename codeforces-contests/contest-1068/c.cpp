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
    map<ll, ll> hs; set<ll> xs;
    vll as(n); for(auto& x : as) {cin >> x; hs[x]++; xs.insert(x);}

    vll ans;
    
    while(!xs.empty())
    {
        ll num = *xs.begin();
        ans.eb(num); xs.erase(xs.begin());
        for(ll i = num; i <= k; i+=num)
        {
            if(!hs.count(i))
            {
                cout << "-1\n";
                return;
            }
            auto it = xs.find(i);
            if(it!=xs.end())
                xs.erase(it);
        }
    }
    
    cout << ans.size() << "\n";
    for(auto a : ans)
        cout << a << ' ';
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
