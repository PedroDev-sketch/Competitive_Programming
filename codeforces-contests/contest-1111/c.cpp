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
    vll a(n), b(n); for(auto& x : a) cin >> x; for(auto& x : b) cin >> x;
    ll zero_to_one = 0, one_to_zero = 0, zero_to_zero = 0, one_to_one = 0;
    for(ll i = 0; i < n; ++i)
    {
        if(a[i]==0&&b[i]==1)
            ++zero_to_one;
        else if(a[i]==1&&b[i]==0)
            ++one_to_zero;
        else if(a[i]==0&&b[i]==0)
            ++zero_to_zero;
        else 
            ++one_to_one;
    }

    if(!one_to_zero&&!zero_to_one)
        cout << "0\n";
    else if(one_to_zero&1)
        cout << "1\n";
    else if(one_to_zero || (zero_to_zero && one_to_one))
        cout << "2\n";
    else
        cout << "-1\n";
    
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
