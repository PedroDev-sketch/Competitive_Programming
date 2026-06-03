#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>

signed main()
{
    ll n, m;
    cin >> n >> m;

    if(n==1 && m==0)
    {
        cout << "1\n";
        return 0;
    }
    
    map<ll, ll> in, out;
    while(m--)
    {
        ll x, y; cin >> x >> y;
        in[y]++;
        out[x]++;
    }

    set<ll> ans;
    for(auto [k, v] : in)
    {
        if(v==(n-1) && !out.count(k))
        {
            ans.insert(k);
        }
    }
    if(ans.size() > 1 || ans.empty())
        cout << "-1\n";
    else
        cout << *ans.begin() << '\n';
}