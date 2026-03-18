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
    vll xs(n); map<ll, ll> hs; set<pll> ys;

    ll idx = 0;
    for(auto& x : xs)
    {
        idx++;
        cin >> x;
        hs[idx] = x;
        ys.emplace(x, idx);
    }

    ll ans = 0;

    while(hs.size()>1)
    {
        while(!hs.count(ys.begin()->ss))
            ys.erase(ys.begin());

        idx = ys.begin()->ss;
        ys.erase(ys.begin());
        auto it = hs.lower_bound(idx);

        if(it==hs.begin())
        {
            auto it1 = hs.rbegin();
            auto it2 = next(it);
            if(it1->ss < it2->ss)
            {
                it->ss = it1->ss;
                ans += it1->ss;
                hs.erase(it1->ff);
            }
            else
            {
                it->ss = it2->ss;
                ans += it2->ss;
                hs.erase(it2->ff);
            }
        }
        else if(it==prev(hs.end()))
        {
            auto it1 = prev(it);
            auto it2 = hs.begin();
            if(it1->ss < it2->ss)
            {
                it->ss = it1->ss;
                ans += it1->ss;
                hs.erase(it1->ff);
            }
            else
            {
                it->ss = it2->ss;
                ans += it2->ss;
                hs.erase(it2->ff);
            }
        }
        else
        {
            auto it1 = prev(it);
            auto it2 = next(it);
            if(it1->ss < it2->ss)
            {
                it->ss = it1->ss;
                ans += it1->ss;
                hs.erase(it1->ff);
            }
            else
            {
                it->ss = it2->ss;
                ans += it2->ss;
                hs.erase(it2->ff);
            }
        }

        ys.insert(mp(it->ss, it->ff));

        //cout << "-> " << ans << '\n';
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
