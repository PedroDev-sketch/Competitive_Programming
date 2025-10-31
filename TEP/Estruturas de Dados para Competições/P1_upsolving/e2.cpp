#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

//This exercise is about the sums of alternated submatrices

ll h, w, k;

void add_lines(const vvll& xs, vvll& ys)
{
    for(ll i = 0; i < h; i++)
    {
        ll sum = 0;
        for(ll j = 0; j < k; j++)
        {
            sum+=xs[i][j];
        }

        ys[i][0] = sum;

        for(ll j = k; j < w; j++)
        {
            sum += xs[i][j];
            sum -= xs[i][j-k];
            ys[i][j-k+1] = sum;
        }
    }
}

void add_columns(vvll& ys, vvll& zs)
{
    for(ll j = 0; j < w-k+1; j++)
    {
        ll sum = 0;
        for(ll i = 0; i < k; i++)
        {
            sum+=ys[i][j];
        }

        zs[0][j] += sum;

        for(ll i = k; i < h; i++)
        {
            sum += ys[i][j];
            sum -= ys[i-k][j];
            zs[i-k+1][j] += sum;
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

    for(ll i = 0; i < h; i++)
        for(ll j = 0; j < w; j++)
            xs[i][j] *= ((i+j)%2==0 ? 1 : -1);

    vvll ys(h, vll(w-k+1, 0));
    add_lines(xs, ys);

    /* for(auto x : ys)
    {
        for(auto y : x)
        {
            cout << y << ' ';
        }
        cout << '\n';
    }cout << '\n'; */
    
    vvll zs(h-k+1, vll(w-k+1, 0));
    add_columns(ys, zs);

    for(ll i = 0; i < h-k+1; i++)
        for(ll j = 0; j < w-k+1; j++)
            zs[i][j] *= ((i+j)%2==0 ? 1 : -1);

    ll ans = zs[0][0];
    for(auto x : zs)
    {
        for(auto y : x)
        {
            //cout << y << ' ';
            ans = max(ans, y);
        }
        //cout << '\n';
    }

    cout << ans << '\n';
}