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
    ll n, idx = 0; cin >> n;
    if(n==1)
        cout << "1\n";
    else if(n<=3)
        cout << "NO SOLUTION\n";
    else
    {
        ll even = 2, odd = 1, cnt = 0;
        while(even<=n)
        {
            cout << even << ' ';
            even += 2;
            ++cnt;
        }
        while(odd <= n && cnt < n)
        {
            cout << odd << ' ';
            odd += 2;
            ++cnt; 
        }
        cout << '\n';
    }
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
