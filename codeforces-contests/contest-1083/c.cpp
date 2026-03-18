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

vll hs(1e6+7, 0);

void solve()
{
    ll n; cin >> n; vvll xs(n);
    for(auto& x : xs)
    {
        ll sz; cin >> sz;
        x.resize(sz);
        vll ys;
        for(auto& y : x) 
        {
            cin >> y;
            hs[y] = 0;
        }

        reverse(all(x));
        for(auto y : x)
        {
            if(!hs[y])
                ys.eb(y);
            ++hs[y];
        }

        for(auto y : ys)
            hs[y] = 0;

        x = ys;
    }

    auto cmp = [&](const vll& a, const vll& b) 
    {
        ll p1 = 0, p2 = 0;
        while (p1 < a.size() && p2 < b.size()) 
        {
            while (p1 < a.size() && hs[a[p1]]) p1++;
            while (p2 < b.size() && hs[b[p2]]) p2++;
            
            if (p1 == a.size() || p2 == b.size()) break;
            
            if (a[p1] != b[p2]) return a[p1] < b[p2];
            p1++; p2++;
        }
        
        while (p1 < a.size() && hs[a[p1]]) p1++;
        while (p2 < b.size() && hs[b[p2]]) p2++;
        
        return p1 == a.size() && p2 < b.size();
    };

    while(!xs.empty())
    {
        auto it = min_element(all(xs), cmp);

        for(auto y : *it)
        {
            if(!hs[y])
            {
                cout << y << ' ';
                hs[y] = 1;
            }
        }

        xs.erase(it);
    }

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
