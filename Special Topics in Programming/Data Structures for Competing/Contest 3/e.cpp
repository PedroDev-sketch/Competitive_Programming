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

vpll moves{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
ll h, w;

void dfs(vector<string>& xs, vvll&ys, ll x, ll y)
{
    stack<pair<pll, ll>> zs;
    zs.push(mp(mp(x, y), 1LL));
    while(!zs.empty())
    {
        pll cd = zs.top().first;

        ll idx = zs.top().second;
        ys[cd.ff][cd.ss] = max(ys[cd.ff][cd.ss], idx);
        zs.pop();
        for(auto [a, b] : moves)
        {
            pll newcd = mp(cd.first+a, cd.second+b);
            if(newcd.ff >= 0 && newcd.ff < h && 
                newcd.ss >= 0 && newcd.ss < w && 
                xs[newcd.ff][newcd.ss] == '.' &&
                !ys[newcd.ff][newcd.ss])
            {
                zs.push(mp(newcd, idx+1));
            }
        }
    }
}

void solve()
{
    cin >> h >> w;
    vector<string> xs(h);
    for(auto& x : xs) cin >> x;

    pll st{0,0};
    for(ll i = 0; i < h; i++)
    {
        for(ll j = 0; j < w; j++)
        {
            if(xs[i][j]=='S') {st = mp(i, j); break;}
        }
    }

    for(ll i = 0; i < 4; i++)
    {
        pll mv = moves[i];
        ll a = mv.ff, b = mv.ss;

        vvll ys(h, vll(w, 0));
        pll tst = mp(st.ff+a, st.ss+b);

        if(tst.ff >= 0 && tst.ff < h && tst.ss >= 0 && tst.ss < w && xs[tst.ff][tst.ss]=='.') 
            dfs(xs, ys, tst.ff, tst.ss);
        else
            continue;

        for(ll j = 0; j < 4; j++)
        {
            if(j!=i)
            {
                pll nmv = moves[j];
                nmv.ff += st.ff, nmv.ss += st.ss;

                if(nmv.ff >= 0 && nmv.ff < h && 
                nmv.ss >= 0 && nmv.ss < w && 
                ys[nmv.ff][nmv.ss] >= 3)
                {
                    cout << "Yes\n";
                    /* cout << nmv.ff << ' ' << nmv.ss << '\n';
                    for(auto x : ys)
                    {
                        for(auto y : x) cout << y << ' ';
                        cout << '\n';
                    }  */

                    return;
                }
            }
        }
    }
    cout << "No\n";
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
