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

vector<string> xs;

void backtrack(ll pos, bool rev, string curr, ll maxsize)
{
    if(pos>=maxsize)
    {
        xs.eb(curr);
        return;
    }

    if(!rev)
    {
        backtrack(pos+1, false, curr+'0', maxsize);
        backtrack(pos+1, true, curr+'1', maxsize);
    }
    else
    {
        backtrack(pos+1, false, curr+'1', maxsize);
        backtrack(pos+1, true, curr+'0', maxsize);
    }
}

void solve()
{
    ll n; cin >> n;
    backtrack(0, '0', "", n);
    for(auto x : xs)
        cout << x << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
