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
    ll n; string s; cin >> n >> s;
    ll pos = 1, ans = 0;
    for(auto x : s)
    {
        if(x=='C')
        {
            ++ans;
            pos = 1;
        }
        else if(x=='D' && (pos==1 || pos==2))
        {
            ++ans;
            pos = 2;
        }
        else if(x=='E' && (pos==1 || pos==0))
        {
            ++ans;
            pos = 0;
        }
        else pos = 1;
    }
    cout << ans << '\n';
}

signed main()
{
    fio;
    solve();
}
