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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s; ll n; cin >> s >> n;
    if(s == "front")
    {
        if(n == 1)
            cout << "L\n";
        else cout << "R\n";
    }
    else
    {
        if(n == 1)
            cout << "R\n";
        else cout << "L\n";
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
