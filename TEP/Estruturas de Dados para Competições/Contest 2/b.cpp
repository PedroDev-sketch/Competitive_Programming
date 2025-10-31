#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define MAXN (1e9 + 7)
#define ff first 
#define ss second

void solve()
{
    vector<string> xs(10);
    for(auto& x : xs) cin >> x;
    ll a=-1, b=-1, c=-1, d=-1;
    for(ll i = 0; i < 10; i++)
    {
        for(ll j = 0; j < 10; j++)
        {
            if(xs[i][j]=='#' && a==-1){a=i+1; c=j+1;}
            if(xs[i][j]=='#') {b=i+1; d=j+1;}
        }
    }

    cout << a << " " << b << '\n' << c << " " << d << '\n';
}

signed main()
{
    fio;
    ll t = 1; //cin >> t;
    while(t--) solve();
}
