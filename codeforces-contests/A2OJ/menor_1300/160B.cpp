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

signed main()
{
    fio;
   
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = s.substr(0, n), s2 = s.substr(n);
    sort(all(s1)); sort(all(s2));
    //reverse(all(s2));

    bool c1 = true, c2 = true;
    for(ll i = 0; i < n; i++)
    {
        if(s1[i] >= s2[i]) c1=false;
        if(s1[i] <= s2[i]) c2=false;
    }

    cout << ((c1 || c2) ? "YES" : "NO") << '\n';
    
    return 0;
}