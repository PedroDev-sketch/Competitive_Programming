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
    ll H, W, N, h, w; cin >> H >> W >> N >> h >> w;

    map<ll, ll> hs, save;

    vvll xs(H, vll(W));
    for(auto& x : xs)
        for(auto& y : x)
        {
            cin >> y;
            hs[y]++;
        }
    save = hs;
    
    ll ansh = H - h + 1, answ = W - w + 1;
    vvll ans(ansh, vll(answ, 0));

    queue<ll> ys;

    for(ll j = 0; j < w; j++)
    {
        for(ll i = 0; i < h; i++)
        {
            ll x = xs[i][j];
            ys.emplace(x);

            hs[x]--;
            if(hs[x] <= 0) hs.erase(x);
        }
    }

    ans[0][0] = hs.size();

    for(ll i = h - 1; i < H; i++)
    {
        if(i != h-1) 
        {
            hs = save;
            queue<ll> as; ys = as;

            for(ll j = 0; j < w; j++)
            {
                for(ll k = i - h + 1; k <= i; k++)
                {
                    ll x = xs[k][j];
                    ys.emplace(x);

                    hs[x]--;
                    if(hs[x] <= 0) hs.erase(x);
                }
            }

            ans[i-h+1][0] = hs.size();
        }
        
        for(ll j = w; j < W; j++)
        {
            for(ll k = i - h + 1; k <= i; k++)
            {
                ll x = ys.front(); ys.pop();
                hs[x]++;

                x = xs[k][j];
                hs[x]--;
                if(hs[x] <= 0) hs.erase(x);
            }

            ans[i - h + 1][j - w + 1] = hs.size();
        }
    }

    for(auto a : ans)
    {
        for(auto e : a) 
            cout << e << ' ';
        cout << '\n';
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
