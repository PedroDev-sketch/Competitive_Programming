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
    ll n; cin >> n;
    vll aji(n), mai(n);
    ll xoraji = 0, xormai = 0;
    for(auto& x : aji) {cin >> x; xoraji^=x;}
    for(auto& x : mai) {cin >> x; xormai^=x;}
 
    if(xoraji==xormai)
    {
        cout << "Tie\n";
        return;
    }

    ll num = (xoraji xor xormai);
    



    cout << ( ? "Ajisai" : "Mai") << '\n';
}
 
signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}