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

signed main()
{
    fio;
    
    ll a, b, n; cin >> a >> b >> n;

    string s = to_string(a);
    ll num = a*10;
    for(ll i = 0; i <= 9; i++)
    {
        ll test = num+i;
        if(test%b==0)
        {
            s += (i + '0');
            break;
        }
    }

    if(stoi(s) == a) cout << -1;
    else
    {
        for(ll i = 0; i < n-1; i++)
            s+='0';
        cout << s;
    }

    cout << '\n';

    return 0;
}
