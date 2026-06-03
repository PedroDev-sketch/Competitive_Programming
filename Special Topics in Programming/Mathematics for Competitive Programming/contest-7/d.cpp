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
    ll hh, mm; cin >> hh >> mm;
    ll h, d, c, n; cin >> h >> d >> c >> n;

    double rn = c * (h/n + (h%n==0 ? 0 : 1));

    if(hh >= 20)
    {
        rn = (c*0.8) * (h/n + (h%n==0 ? 0 : 1));
        cout << fixed << setprecision(4) << rn << '\n';
        return;
    }

    double newc = c*0.8;
    ll time_left = (20-hh)*60 - mm;
    h += time_left * d;
    double lat = newc * (h/n + (h%n==0 ? 0 : 1));
    cout << fixed << setprecision(4) << min(rn, lat) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
