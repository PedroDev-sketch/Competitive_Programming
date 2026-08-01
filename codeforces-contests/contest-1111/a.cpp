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
    ll n, sum = 0; cin >> n;
    vll xs(n); for(auto& x : xs) {cin >> x; sum += x;}

    if(n&1 || sum&1)
    {
        cout << "NO\n";
        return;
    }

    for(ll i = 1; i < n; ++i)
    {
        if(sum < 0LL && xs[i]==-1 && xs[i-1]==-1)
        {
            sum += 4;
            xs[i] = 1;
            xs[i-1] = 1;
        }
        else if(sum > 0LL && xs[i]==1 && xs[i-1]==1)
        {
            sum -= 4;
            xs[i] = -1;
            xs[i-1] = -1;
        }
    }

    cout << (sum ? "NO\n" : "YES\n");
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
