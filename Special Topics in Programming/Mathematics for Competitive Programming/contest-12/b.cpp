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
    ll n; cin >> n;
    string s, t = ""; cin >> s;

    for(auto x : s)
    {
        ll num = (x-'0');
        if(num&1)
            t.push_back(x);
    }

    if(t.size()&1)
        t.pop_back();

    if(t.empty())
    {
        cout << "-1\n";
        return;
    }

    cout << t << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
