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
    ll n, x, y, d; cin >> n >> x >> y >> d;
    vll ans;

    //x
    ll m = abs(x-y)/d;

    if(y + m*d == x || x + m*d == y)
        ans.eb(m);

    //cout << "x: " << m << '\n';

    //1
    ll dist = (x-1)/d+((x - 1)%d!=0);
    if(x==1)
        dist = 0;
    m = (y-1)/d;

    if(m*d + 1 == y)
        ans.eb(dist+m);

    //cout << "1: " << dist+m << '\n';

    //n
    dist = (n-x)/d + ((n-x)%d!=0);
    if(x==n)
        dist = 0;
    m = (n-y)/d;

    //cout << "n: " << m << '\n';

    if(n - m*d == y)
        ans.eb(dist+m);

    /* for(auto a : ans) cout << a << ' ';
    cout << "<- \n"; */

    cout << (ans.empty() ? -1 : *min_element(all(ans))) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
