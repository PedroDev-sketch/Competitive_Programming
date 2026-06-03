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
    double x; cin >> x;
    x = (x*3.14159)/180;
    double a = sin(x), b = cos(x);
    if(abs(a-b) <= 1e-5)
        cout << "Ambos";
    else if(b > a)
        cout << "Costa";
    else cout << "Saad";
}

signed main()
{
    fio;
    solve();
}
