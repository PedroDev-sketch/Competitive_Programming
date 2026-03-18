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

// fazer contagem de 1s por cada coluna e
// ir separando com base nisso.
// OBJ: Pegar metade dos 1s, pode ser ceil ou floor
void solve()
{
    ll n, m, total = 0; cin >> n >> m;

    vvll xs(n, vll(m));
    for(auto& x : xs)
        for(auto& y : x)
        {
            cin >> y;
            if(y) ++total;
        }
    
    ll curr = 0, goal = total/2;
    string ans = "";
    vpll pos;
    
    ll ci = 0;
    for(ll j = 0; j < m; ++j)
    {
        ll i = n-1;
        for(; i>=0 && i >= ci && curr+xs[i][j] <= goal; --i)
            curr+=xs[i][j];
        ci = max(ci, i);
        pos.eb(i, j);
    }

    /* for(auto [x, y] : pos)
        cout << "{" << x << ", " << y << "}\n"; */

    ll i = 0, j = 0;
    for(auto [x, y] : pos)
    {
        while(i <= x)
        {
            ++i;
            ans += "D";
        }
        while(j <= y)
        {
            ++j;
            ans += "R";
        }
    }

    while(j < m)
    {
        ++j;
        ans+='R';
    }

    while(i < n)
    {
        ++i;
        ans+='D';
    }

    cout << (total&1 ? total/2 * (total/2+1) : total/2 * total/2) << '\n';
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
