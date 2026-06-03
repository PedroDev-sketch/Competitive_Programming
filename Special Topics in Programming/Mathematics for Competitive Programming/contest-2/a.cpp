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

//S = (v1+v2)*t
//L - S <= d 
//-(v1+v2)*t <= d-L
//(v1+v2)*t >= L-d
void solve()
{
    double d, L, v1, v2; cin >> d >> L >> v1 >> v2;
    double time = (L-d)/(v1+v2);
    cout << fixed << setprecision(20) << time << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
