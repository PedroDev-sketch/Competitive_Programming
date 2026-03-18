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
    string s, t; cin >> s >> t;
    map<char, ll> hs, ht;
    for(auto x : s)
        hs[x]++;
    for(auto x : t)
        ht[x]++;

    for(auto [x, y] : hs)
    {
        if(ht[x] < y)
        {
            cout << "Impossible\n";
            return;
        }
        ht[x] -= y;
    }

    string ans = ""; ll idx = 0;
    for(auto [x, y] : ht)
    {
        while(idx < s.size() && x >= s[idx])
        {
            ans += s[idx];
            idx++;
        }
        if(x < s[idx] || idx >= s.size())
            while(y--)
                ans += x;
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
