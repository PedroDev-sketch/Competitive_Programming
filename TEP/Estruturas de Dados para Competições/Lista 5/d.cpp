#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll ans = 0;
    string s; cin >> s;
    ll num = (ll)s.size();
    for(ll i = 0; i < (1 << (num-1)); i++)
    {
        string curr = ""; ll buff = 0;
        for(ll j = 0; j < num; j++)
        {
            curr += s[j];
            if(j < num-1 && ((i >> j) & 1)) 
            {
                buff += stoll(curr);
                curr = "";
            }
        }
        if(curr != "") buff += stoll(curr);
        ans += buff;
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    //ll t; cin >> t;
    solve();
    return 0;
}