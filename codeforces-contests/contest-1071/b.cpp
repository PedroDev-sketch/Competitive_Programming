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
    vll xs(n); for(auto& x : xs) cin >> x;
    pair<ll, ll> rem{0,0};
    for(ll i = 1; i < n; i++) 
    {
        ll num = abs(xs[i] - xs[i-1]), num2 = 0;
        sum += num;
        ll diff = num;

        if(i < n -1)
        {
            num2 = abs(xs[i+1] - xs[i]);
            diff += abs(num-num2);
        }

        if(diff >= rem.ff)
        {
            rem.ff = diff;
            rem.ss = num+num2-abs(num-num2);
        }
    }
    //cout << "sum-> " << sum << " : " << rem.ff << " - " << rem.ss << '\n';
    cout << sum-rem.ff << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
