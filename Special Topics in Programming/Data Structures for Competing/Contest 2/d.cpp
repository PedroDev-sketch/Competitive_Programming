#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define MAXN (1e9 + 7)
#define ff first 
#define ss second

vpll moves = {{0, 0}, {-1,-1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};

void solve()
{
   ll n; cin >> n;
   map<pll, ll> hs;
   vpll xs(n); 
   for(auto& [x, y] : xs) 
   {
        cin >> x >> y;
        hs[mp(x, y)] = -39;
   }
   
   ll ans = 0; ll idx = 2;
   for(auto x : xs)
   {
        pll curr = x;
        queue<pll> zs;
        zs.push(x);

        while(!zs.empty())
        {
            curr = zs.front();
            zs.pop();
            for(auto [a, b] : moves)
            {
                pll now = mp(curr.ff+a, curr.ss+b);
                if(hs.count(now) && hs[now]==-39)
                {
                    zs.push(now);
                    hs[now] = idx;
                }
            }
        }

        idx++;
   }

   set<ll> ys;
   for(auto h : hs)
   {
        //cout << "-> (" << h.first.first << "," << h.first.second << ") - " << h.second << '\n';
        ys.insert(h.second);
   }
   cout << ys.size() << '\n';
}

signed main()
{
    fio;
    ll t = 1; //cin >> t;
    while(t--) solve();
}
