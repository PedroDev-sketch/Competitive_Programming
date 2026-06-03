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


signed main()
{
    fio;
    
    ll n; string s;
    cin >> n >> s;
    
    queue<ll> xs;
    ll last = s[0] - '0', op = 0;
    for(auto p : s) 
    {
        ll newp = (p - '0');

        if(last != -1 && newp != last && !xs.empty())
        {
            op += 2;
            last = xs.front();
        }

        else {xs.push(newp); last = newp;}
    }

    cout << abs(n - op) << '\n';

    return 0;
}