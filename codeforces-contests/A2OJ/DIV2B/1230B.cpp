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
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    if(k && s.size()==1)
    {
        cout << "0\n";
        return 0;
    }

    if(s[0]!='1' && k){s[0]='1'; k--;}
    for(ll i = 1; i < n && k; i++)
    {
        if(s[i]!='0')
        {
            s[i]='0';
            k--;
        }
    }

    cout << s << '\n';

    return 0;
}
