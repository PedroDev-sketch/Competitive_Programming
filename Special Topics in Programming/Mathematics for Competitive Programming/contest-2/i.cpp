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

ll divs(ll num)
{
    if (num <= 1) return 1;
    for (ll i = 2; i * i <= num; ++i) 
        if (num % i == 0) 
            return i;
    return num;
}

void solve()
{
    ll n, m, ans = 0; cin >> n >> m;
    vll xs(n), ys(m); map<ll, ll> hs;
    for(auto& x : xs) cin >> x; for(auto& y : ys) cin >> y;

    auto f = [&](ll num) -> ll 
    {
        if(hs.count(num)) return hs[num];
        
        ll orig = num;
        ll score = 0;

        for(ll i = 2; i*i <= num; ++i)
        {
            while(num % i == 0)
            {
                if(binary_search(all(ys), i)) score -= 1;
                else score += 1;
                num /= i;
            }
        }

        if (num > 1) 
        {
            if(binary_search(all(ys), num)) score -= 1;
            else score += 1;
        }
        return hs[orig] = score;
    };

    for(auto x : xs)
        ans += f(x);

    vll gs(n); gs[0] = xs[0];
    for(ll i = 1; i < n; ++i)
        gs[i] = gcd(gs[i-1], xs[i]);

    ll curr = 1;
    for(ll i = n-1; i >= 0; --i)
    {
        ll g = gs[i] / curr;
        ll buff = f(g);

        if(buff < 0)
        {
            ans -= buff*(i+1);
            curr *= g;
        }
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
