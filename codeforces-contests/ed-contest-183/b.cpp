#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define MAXN (1e9 + 7)
#define ff first 
#define ss second 

void solve()
{
    ll n, k; cin >> n >> k;

    string s; cin >> s;
    ll h = n;
    string p = "";
    while(h--) p+='+';
    ll idxt = 0, idxb = n-1;
    bool flag = false;

    ll x = 0, y = 0, z = 0;
    if(n == k)
    {
        for(auto& i : p) i = '-';
    }

    else 
    {
        for(auto i : s)
        {
            if(i=='0')x++;
            else if(i=='1') y++;
            else z++;
        }

        for(ll i = 0; i < x; i++)
            p[i] = '-';
        for(ll i = n-1; i > ((n-1)-y); i--)
            p[i] = '-';
        for(ll i = x; i <= ((n-1)-y) && i < n && i < (x+z); i++)
            p[i] = '?';
        for(ll i = ((n-1)-y); i >= x && i >= 0 && i > ((n-1)-y) - z; i--)
            p[i] = '?';

    }
    
    cout << p << '\n';
}

signed main()
{
    fio;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}
