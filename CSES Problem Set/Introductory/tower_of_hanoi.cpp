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

queue<pll> ans;

void hanoi(ll disk, ll src, ll target)
{
    if(disk <= 0)
        return;
    ll aux = 3 - target - src;
    hanoi(disk-1, src, aux);
    ans.push({src, target});
    hanoi(disk-1, aux, target);
}

void solve()
{
    ll n; cin >> n;
    hanoi(n, 0, 2);
    cout << ans.size() << '\n';
    while(!ans.empty())
    {
        cout << ans.front().ff + 1 << " " << ans.front().ss+1 << '\n';
        ans.pop();
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
