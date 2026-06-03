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
    string a; cin >> a;
    string ans = ""; ll zero = 0;
    set<ll> xs {'1', '8', '9', '6'};
    for(auto x : a)
    {
        if(x=='0')
        {
            zero++;
            continue;
        }

        auto it = xs.find(x);
        if(it!=xs.end())
            xs.erase(it);
        else ans.push_back(x);
    }

    ll rem = 0;
    for(auto c : ans) 
        rem = (rem * 10 + (c - '0')) % 7;

    rem = (7 - (rem*4)%7)%7;
    string nums[7] = {"1869", "1968", "1689", "6198", "1698", "1986", "1896"};

    ans += nums[rem];
    while(zero--)
        ans.push_back('0');
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
