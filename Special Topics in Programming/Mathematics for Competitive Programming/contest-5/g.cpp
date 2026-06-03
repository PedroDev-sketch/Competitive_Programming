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
    vll xs(n); for(auto& x : xs) cin >> x;
    string s; cin >> s;

    for(ll i = 0; i < n-1;)
    {
        if(s[i]=='1')
        {
            ll j = i;
            while(j < n-1 && s[j]=='1')
                ++j;

            sort(xs.begin()+i, xs.begin()+j+1);
            i = j;
        }
        else ++i;
    }

    cout << (is_sorted(all(xs)) ? "YES" : "NO") << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
