#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

void solve()
{
    ll n; cin >> n;
    string s; cin >> s;
    
    ll cnt = 0, len = 1; 
    char last = s[0];
    
    ll zero = 0, one = 0;
    for(auto x : s) 
    {
        if(x=='0') zero++; 
        else one++;
    }
    
    if(abs(zero-one)>2)
    {
        cout << "-1\n";
        return;
    }

    ll czero = 0, cone = 0;
    if (s[0] == '0') czero++;
    else cone++;
    for(ll i = 1; i < n; ++i)
    {
        if(s[i] != s[i-1])
        {
            if(s[i]=='1') ++cone;
            else ++czero;
        }
    }

    ll ans = -1, diff = zero-one;
    if(abs(diff) <= 1 && min(cone, czero) >= 1)
        ans = max(ans, 2*min(czero,cone));

    if(abs(diff-1) <= 1 && czero >= 1)
        ans = max(ans, 2*czero - 1);

    if(abs(diff+1) <= 1 && cone >= 1)
        ans = max(ans, 2*cone -1);

    cout << (ans == -1 ? ans : n - ans) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
