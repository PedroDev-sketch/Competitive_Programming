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
    
    ll cnt = 0, back = n-1, blocks = 0;
    for(auto& x : xs) 
    {
        cin >> x;
        if(x>=2)
        {
            cnt += x;
            ++blocks;
        }
    }

    bool shave = false;
    ll ones = count(all(xs), 1LL);

    for(ll i = 0; i < ones; ++i)
    {
        ll req = (!shave && blocks > 1) ? 4 : 2;

        if(xs[back] >= req)
        {
            if(!shave && blocks > 1)
            {
                xs[back] -= 2;
                shave = true;
            }

            cnt += 1;
            xs[back] -= 2;

            if(xs[back] < 2)
            {
                back = max(back-1LL, 0LL);
                shave = false; 
            }
        }
        
    }

    cout << (cnt >= 3 ? cnt : 0) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
