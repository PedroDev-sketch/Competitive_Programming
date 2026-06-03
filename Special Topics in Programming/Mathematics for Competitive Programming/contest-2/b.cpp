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
    ll n, cnt1 = 0, cnt2 = 0; cin >> n;
    string s; cin >> s;
    for(ll i = 0; i < n; ++i)
    {
        string t; cin >> t;
        string st = t.substr(0, 3);
        string ts = t.substr(5, 3);
        if(st==s)
            ++cnt1;
        else if(ts==s)
            ++cnt2;
    }

    if(cnt2 < cnt1)
        cout << "contest";
    else
        cout << "home";
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
