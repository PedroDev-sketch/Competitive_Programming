#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vvll = vector<vll>;
using vpll = vector<pll>;

#define all(xs) xs.begin(), xs.end()
#define rep(i, a, b) {for(ll i = (a); i <= (b); i++)}
#define fio cin.tie(0)->ios::sync_with_stdio(0)

signed main()
{
    fio;

    ll t;
    cin >> t;
    while(t--)
    {
        ll a, b;
        bool ans = true;

        cin >> a >> b;
        if(a > b && (a - (b*2)) > 2) ans = false;
        else if(a < b && (b - (a*2)) > 2) ans = false;

        ll c, d;
        cin >> c >> d;
        c-=a; d-=b;
        if(c> d && (c- (d*2)) > 2) ans = false;
        else if(c< d && (d - (c*2)) > 2) ans = false;

        cout << (ans ? "Yes" : "No") << '\n';
    }

    return 0;
}