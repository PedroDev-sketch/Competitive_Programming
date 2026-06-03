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
    ll n, ones = 0, twos = 0; cin >> n;
    vll xs(n); for(auto& x : xs) 
    {
        cin >> x;
        if(x==1) ones++;
        else twos++;
    }

    ll a = twos, b = twos+2*(twos&1);
    if((a==b && !(ones&1)) || (a!=b && !(ones&1) && ones >= 2))
        cout << "YES\n";
    else cout << "NO\n";
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
