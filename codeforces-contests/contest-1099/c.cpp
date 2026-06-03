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
    vpll hs;
    vll xs(n); for(auto& x : xs) cin >> x;
    
    for(auto x : xs)
    {
        ll cnt = 0;
        bool istwohere = (x==2);
        hs.eb(x, cnt);

        while(x>1)
        {
            if(x&1)
                ++x;
            else 
                x >>= 1;
            ++cnt;

            if(x==2)
                istwohere = true;
                
            hs.eb(x, cnt);
        }

        if(!istwohere)
            hs.eb(2, cnt+1);
    }

    sort(all(hs));

    ll ans = LLONG_MAX;
    ll last = -1, cnt = 0, steps = 0;
    for(auto [key, val] : hs)
    {
        steps += val;
        if(key==last)
            ++cnt;
        else
        {
            cnt = 1;
            steps = val;
        }

        if(cnt==n)
            ans = min(ans, steps);
        
        last = key;
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
