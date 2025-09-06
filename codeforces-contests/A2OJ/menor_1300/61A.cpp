#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

signed main()
{
    fio;
    string s, t;
    cin >> s >> t;

    string p = "";
    for(size_t i = 0; i < s.size(); i++)
    {
        ll x = s[i] - '0', y = t[i] - '0';
        ll ans = x xor y;
        p += to_string(ans);
    }

    cout << p << '\n';
}