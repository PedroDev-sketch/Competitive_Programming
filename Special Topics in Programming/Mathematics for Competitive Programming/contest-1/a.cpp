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
    string n; cin >> n;

    vector<string> xs;
    for(ll i = 0; i < n.size(); ++i)
    {
        if(n[i]!='0')
        {
            string news = ""; news += n[i];
            for(ll j = i+1; j < n.size(); ++j)
                news += '0';
            xs.eb(news);
        }
    }

    cout << xs.size() << '\n';
    for(auto x : xs) cout << x << ' ';
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
