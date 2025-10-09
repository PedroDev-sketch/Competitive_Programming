#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,vll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void path(vpll& xs, pll& ys, ll& time, vll& learned)
{
    time += ys.first;
    if(ys.second.size() > 0)
    {
        for(auto y : ys.second)
        {
            if(learned[y-1])
                continue;
            else
            {
                learned[y-1] = 1;
                path(xs, xs[y-1], time, learned);
            }
        }
    }
}

void solve()
{
    ll n; cin >> n;
    vpll xs(n);
    for(auto& x : xs)
    {
        ll m, k; cin >> m >> k;
        x.first = m;
        vll ys(k);
        for(auto& y : ys) cin >> y;
        x.second = ys;
    }

    ll time = 0;
    vll learned(n, 0);
    learned[n-1] = 1;
    path(xs, xs[n-1], time, learned);
    cout << time << '\n';
}

signed main()
{
    fio;
    //ll t; cin >> t;
    solve();
    return 0;
}