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
    ll x, y, x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
	
	if(abs(x1-x2)%abs(x)==0 && abs(y1-y2)%abs(y)==0
		&& abs(abs(x1-x2)/abs(x) - abs(y1-y2)/abs(y))%2==0)
		cout << "YES\n";
	else cout << "NO\n";
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
