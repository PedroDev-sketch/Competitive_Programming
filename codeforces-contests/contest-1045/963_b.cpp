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
#define all(xs) xs.begin(), xs.end()

signed main()
{
    fio;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        vll xs(n);
        ll odd = 0, maxodd = 0;
        for(auto& x : xs) 
        {
            cin >> x; 
            if(x%2) 
            {
                odd++;
                maxodd = max(maxodd, x);
            }
        }

        ll bigger_even = 0;
        for(auto x : xs) if(x%2 == 0 && x > maxodd) bigger_even++;

        if(!odd || odd == n)
        {
            cout << 0 << '\n';
            continue;
        }

        sort(all(xs));

        ll badcase = 0;
        for(auto x : xs)
        {
            if(x % 2 == 0)
            {
                if(x < maxodd) {maxodd = maxodd+x;}
                else {badcase = 1;}
            }
        }

        cout << n-odd+badcase << '\n';
    }

    return 0;
}