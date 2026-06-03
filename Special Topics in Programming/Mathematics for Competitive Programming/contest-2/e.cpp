#include <bits\stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(xs) xs.begin(), xs.end()

signed main()
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n, ones = 0, bckzero = 0; string s, t; cin >> n >> s >> t;
	for(ll i = 0; i < n; ++i)
	{
		if(s[i]=='1')
			++ones;
		if(s[i]=='0' && t[i]=='1')
			++bckzero;
	}

	ll ans = 0;
	for(ll i = 0; i < n; ++i)
		if(t[i]=='0')
		{
			if(s[i]=='1')
				ans += bckzero;
			else
				ans += ones;
		}
	cout << ans << '\n';
}