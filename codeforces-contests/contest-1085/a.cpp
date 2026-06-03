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
    ll n; string s; cin >> n >> s;
    string saves = s;
    
    ll low = 0, high = 0;
    for(ll i = 0; i < n; ++i)
    {
        if(s[i]=='1')
        {
            if(i-1 >= 0 && i+1 < n && s[i-1]=='1' && s[i+1]=='0')
            {
                s[i] = '0';
                s[i+1] = '1';
            }
            else if(i-1 >= 0 && i+1 < n && s[i-1]=='1' && s[i+1]=='1') s[i] = '0';
            else ++low; 
        }
    }

    for(ll i = 0; i < n; ++i)
    {
        if(saves[i]=='1')
            ++high;
        else if(i-1 >= 0 && i+1 < n && saves[i-1]=='1' && saves[i+1]=='1')
            ++high;
    }

    cout << low << " " << high << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
