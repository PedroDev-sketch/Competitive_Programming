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
    string s, t, h;
    cin >> s >> t >> h;

    map<char, char> hs;
    for(ll i = 0; i < 26; i++)
        hs[s[i]] = t[i];

    for(auto& str : h)
    {
        if(str >= 65 && str <= 91)
        {
            str += 'a' - 'A';
            str = hs[str];
            str += 'A' - 'a';
        }
        else if(str >= 97 && str <= 123) str = hs[str];
    }

    cout << h << '\n';

    return 0;
}
