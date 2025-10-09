#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define eb emplace_back
#define mp make_pair

void add_str(multiset<ll>& str, multiset<ll>& kindergarten)
{
    if(!kindergarten.empty())
        str.insert(*kindergarten.rbegin());
    
}

void remove_str(multiset<ll>& str, multiset<ll>& kindergarten)
{
    if(!kindergarten.empty())
        str.erase(str.find(*kindergarten.rbegin()));
    
}

void solve()
{
    ll n, q; cin >> n >> q;
    vpll xs(n);
    vector<multiset<ll>> k_roster(200'000 + 7);
    multiset<ll> str;
    for(auto& [x, y] : xs)
    {
        cin >> x >> y;
        k_roster[y].insert(x);
    }  

    for(auto h : k_roster)
        if(!h.empty())
            str.insert(*h.rbegin());
    

    while(q--)
    {
        ll c, d; cin >> c >> d;

        ll origin_r = xs[c-1].first;
        ll origin_k = xs[c-1].second;

        xs[c-1].second = d;
        
        remove_str(str, k_roster[origin_k]);
        k_roster[origin_k].erase(k_roster[origin_k].find(origin_r));
        add_str(str, k_roster[origin_k]);

        remove_str(str, k_roster[d]);
        k_roster[d].insert(origin_r);
        add_str(str, k_roster[d]);

        cout << *str.begin() << '\n';
    }
}

signed main()
{
    fio;
    //ll t; cin >> t;
    solve();
    return 0;
}