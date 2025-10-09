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
    string s;cin >> s;
    auto it = s.find('0');
    if(it != string::npos)
    {
        ll idx = (ll) it;
        s = s.substr(0, idx) + s.substr(idx+1);
    }
    else s = s.substr(1);
    cout << s << '\n';
    return 0;
}