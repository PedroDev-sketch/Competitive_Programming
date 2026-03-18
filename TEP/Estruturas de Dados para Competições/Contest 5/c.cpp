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
#define MAXN (1e9 + 7)
#define ff first
#define ss second

void solve()
{
   ll n, q; cin >> n >> q;
   map<ll,multiset<ll>> hs; 

   while(q--)
   {
        ll t, x, y; cin >> t >> x >> y;
        if(t==1)
            hs[y].emplace(x);
        else if(t==2)
            hs[y].erase(x);
        else
        {
            auto it1 = hs[y].find(x);
            auto it2 = hs[x].find(y);

            if(it1 != hs[y].end() && it2 != hs[x].end())
                cout << "Yes";
            else cout << "No";
            cout << '\n';
        }
   }
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
