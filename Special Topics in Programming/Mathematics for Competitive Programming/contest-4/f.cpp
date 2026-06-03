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

const ll mod = 998244353;

void solve()
{
	ll n; string s; cin >> n >> s;
	bool scene = s[0]==s.back();
	ll ans = 0, cnt1 = 1, cnt2 = 1;
	for(ll i = 1; i < n && s[i]==s[i-1]; ++i)
		++cnt1;
	for(ll i = n-2; i >= 0 && s[i]==s[i+1]; --i)
		++cnt2;

	if(scene)
		ans = (cnt1+1)*(cnt2+1);
	else
		ans = cnt1+cnt2+1;

	cout << ans%mod << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
