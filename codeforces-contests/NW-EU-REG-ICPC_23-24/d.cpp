#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back
#define ff first
#define ss second
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void find_intersec(vector<string> ys, ll size, ll h, double&ans)
{
    vll zs(24, 0);
    for(ll i = 0; i < size; i++)
    {
        for(ll j = 0; j < 24; j++)
        {
            if(ys[i][j]=='.')
                zs[j]++;
        }
    }

    sort(all(zs), greater<>());
    ll free = 0, nfree = 0;
    for(ll i = 0; i < h; i++)
    {
        nfree += size;
        free += zs[i];
    }

    double buff = (double)free/(double)nfree;
    ans = max(ans, buff);
}

// #define meujeitoninjaoualgumacoisaassim
void backtrack(const vector<string>& xs, vector<string> ys, ll size, ll start, ll d, ll h, double& ans)
{
    if(size==d)
    {
        find_intersec(ys, d, h, ans);
    }

    if(start > 7)
        return;

    backtrack(xs, ys, size, start+1, d, h, ans);

    if(start+1 < 7)
    {
        ys.eb(xs[start+1]);
        backtrack(xs, ys, size+1, start+1, d, h, ans);
    }
}

void solve(vector<string> &xs, ll d, ll h)
{
    double ans = 0;
    for(ll i = 0; i < 7; i++)
    {
        vector<string> ys;
        ys.eb(xs[i]);
        backtrack(xs, ys, 1, i, d, h, ans);
    }
    cout << fixed << setprecision(9) << ans << '\n';
}

signed main()
{
    fio;
    vector<string> xs(7);
    for(auto& x : xs) cin >> x;
    ll d, h; cin >> d >> h;
    solve(xs, d, h);
}
