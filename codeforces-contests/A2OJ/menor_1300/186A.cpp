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
    string s, t;
    cin >> s >> t;

    ll check = 0;
    bool ans = false;
    map<char,ll>hs;
    for(int i = 0; i < (ll)min(t.size(), s.size()); i++)
    {
        if(s[i] != t[i]) {check++; hs[s[i]]++; hs[t[i]]++;}
    }

    if(check == 2 && hs.size() == 2) ans = true;
    cout << ((ans && s.size() == t.size()) ? "YES" : "NO") << '\n';
    return 0;
}