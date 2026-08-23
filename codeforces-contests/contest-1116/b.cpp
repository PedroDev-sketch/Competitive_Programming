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

    ll ans = 0;

    auto check_seq = [&](ll num, ll cnt)
    {
        ll flag = 1;
        for(ll i = 2; i < n; ++i)
        {
            if((s[i]==(num+'0') || s[i]=='?') && cnt)
            {
                num = 1-num;
                cnt = 0;
            }
            else if(s[i]==(num+'0') || s[i]=='?')
                ++cnt;
            else return;
        }
        ans += flag;
        return;
    };

    if(s[0]=='1' || s[0]=='?')
    {
        if(s[1]=='0' || s[1]=='?')
            check_seq(0, 1); 
        if(s[1]=='1' || s[1]=='?')
            check_seq(0, 0); 
    }

    if(s[0]=='0' || s[0]=='?')
    {
        if(s[1]=='0' || s[1]=='?')
            check_seq(1, 0); 
        if(s[1]=='1' || s[1]=='?')
            check_seq(1, 1); 
    }

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}