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
    ll n, m, k; cin >> n >> m >> k;
    ll l = 0, r = 0;

    ll flag = 0, ans = 0;
    while(l+r+max(l,r)-1 <= m)
    {
        flag = 0;
        if(r < n-k && l+r+max(l,r+1) <= m)
        {
            ++r;
            flag = 1;
        }
        if(l < k-1 && l+r+max(l+1,r) <= m)
        {
            ++l;
            flag = 2;
        }
        if(!flag)
            break;
    }
    cout << l+r+1 << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
