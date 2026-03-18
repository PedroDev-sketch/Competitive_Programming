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

// 1 2 or 2 1
// 2 3 1 or 2 1 3
// 2 3 1 4
// 3 2 4 1 5
void solve()
{
    ll n; cin >> n;
    stack<ll> xs; map<ll,ll> hs;
    xs.push(n); xs.push(1);
    hs[1]++; hs[n]++;
    ll idx = n-2;
    while(xs.size()!=n)
    {
        ll num = xs.top()+idx;
        if(hs.count(num) || num > n)
            num -= 2*idx;
        xs.push(num);
        hs[num]++;
        idx--;
    }
    while(!xs.empty())
    {
        cout << xs.top() << ' ';
        xs.pop();
    }
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
