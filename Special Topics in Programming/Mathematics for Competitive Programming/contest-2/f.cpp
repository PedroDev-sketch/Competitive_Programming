#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(xs) xs.begin(), xs.end()

signed main()
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll l, r; cin >> l >> r;
	set<ll> ans;
	if(l==1) ans.insert(1);
	for(ll y = 3; y <= 2e9+7; y*=3)
    	for(ll x = 2; x <= 2e9+7; x*=2)
    	{
    		if(x >= l && x <= r)
    			ans.insert(x);
    		if(y >= l && y <= r)
    			ans.insert(y);
    		if(x*y >= l && x*y <= r)
    			ans.insert(x*y);
    	}
	cout << ans.size() << '\n';
}