#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

//This exercise is about the sums of alternated submatrices

ll h, w, k;

void in_range(vvll& zs, vvll& xs, ll x, ll y)
{
    for(ll i = 0; i <= h-k; i++)
    {
        for(ll j = 0; j <= w-k; j++)
        {
            if((x-i) < k && (y-j) < k && x>=i && y>=j)
            {
                zs[i][j] += xs[x][y] * pow(-1, (x-i)+(y-j));

                //cout << i << " " << j << " -> " << xs[x][y] * pow(-1, (x-i)+(y-j)) << '\n';
            }
        }
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cin >> h >> w >> k;
    vvll xs(h);
    for(auto& x : xs)
    {
        vll ys(w);
        for(auto& y : ys) cin >> y;
        x = ys;
    }

    vvll zs(h-k+1, vll(w-k+1, 0));
    for(ll i = 0; i < h; i++)
    {
        for(ll j = 0; j < w; j++)
        {
            in_range(zs, xs, i, j);
        }
    }

    ll ans = zs[0][0];
    //cout << '\n';
    for(auto z : zs)
    {
        for(auto h : z)
        {
            //cout << h << " ";
            ans = max(ans, h);
        }
        //cout << '\n';
    }
    cout << ans << '\n';
}