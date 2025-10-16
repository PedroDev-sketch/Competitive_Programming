#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define MAXN (1e9 + 7)
#define ff first 
#define ss second

signed main()
{
    fio;
    ll n; string s;
    cin >> n >> s;

    deque<char> xs;
    ll idx = (n%2==0);
    for(auto h : s)
    {
        if(idx%2)
            xs.push_front(h);
        else
            xs.push_back(h);
        idx++;
    }

    for(auto x : xs) cout << x;
    cout << '\n';

    return 0;
}
