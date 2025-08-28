#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vvll = vector<vll>;
using vpll = vector<pll>;

#define rep(i, a, b) for(ll i = (ll) a; i < (ll) b; i++);
#define per(i, a, b) for(ll i = (ll) a; i >= (ll) b; i--);
#define fio cin.tie(0)->sync_with_stdio(0)

signed main()
{
    fio;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;

        bool ans = false;
        if(n%2 == b%2)
        {
            if(b >= a) ans = true;
            else if(a%2 == n%2) ans = true;
        }

        cout << (ans ? "Yes" : "No") << '\n';
    }

    return 0;
}