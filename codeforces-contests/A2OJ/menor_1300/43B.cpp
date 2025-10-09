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

void backtrack()
{

}

signed main()
{
    fio;
    
    string s, t;
    getline(cin, s);
    getline(cin, t);

    map<char, ll> hs;
    for(auto p : s) hs[p]++;

    for(auto p : t)
    {
        if(p != ' ')
        {
            hs[p]--;
            if(hs[p] < 0)
            {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }

    cout << "YES" << '\n';

    return 0;
}