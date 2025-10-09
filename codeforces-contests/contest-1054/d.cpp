#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define eb emplace_back

void solve()
{
    ll n; cin >> n;
    string s; cin >> s;
    vll posa, posb;
    for(ll i = 0; i < n; i++)
    {
        if(s[i]=='a') posa.eb(i);
        else posb.eb(i);
    }

    //cout << "debug1\n";

    ll ma = 0, mb = 0;
    if(!posa.empty()) ma = posa[ max(((ll)posa.size()-1), (ll)0) / 2 ];
    if(!posb.empty()) mb = posb[ max(((ll)posb.size()-1), (ll)0) / 2 ];

    //cout << "debug2\n";

    ll ans_a = 0, ans_b = 0;
    for(ll i = 0; i < (ll)posa.size(); i++)
    {
        ll a = posa[i];
        if(a < ma) 
        {
            ans_a += (ma-a) - ((posa.size()-1)/2 - i);
        }
        else if(a > ma)
        {
            ans_a += (a-ma) - (i - (posa.size()-1)/2);
        }
    }

    //cout << "debug3\n";

    for(ll i = 0; i < (ll)posb.size(); i++)
    {
        ll b = posb[i];
        if(b < mb) 
        {
            ans_b += (mb-b) - ((posb.size()-1)/2 - i);
        }
        else if(b > mb)
        {
            ans_b += (b-mb) - (i - (posb.size()-1)/2);
        }
    }

    //cout << "debug4\n";
    
    cout << min(ans_a, ans_b) << '\n';
}

signed main()
{
    fio;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}