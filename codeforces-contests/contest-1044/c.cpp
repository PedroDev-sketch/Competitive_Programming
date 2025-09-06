#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vvll = vector<vll>;
using vpll = vector<pll>;

#define all(xs) xs.begin(), xs.end()
#define eb emplace_back

signed main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n; 
        cin >> n;

        vpll xs;
        
        for(int x = 1; x <= n; x++)
        {
            cout << "? " << x << " " << n << " ";
            for(int i = 1; i <= n; i++) cout << i << " ";
            cout << '\n' << flush;

            ll num;
            cin >> num;

            xs.eb(num, x);
        }

        sort(all(xs), greater<>());
        auto[xi, yi] = xs[0];

        vll ans{yi};

        ll k = xi;
        ll t = yi;
        while(true && ans.size() < xi)
        {
            vpll less;
            for(auto [x, y] : xs)
            {
                if(x == k-1) less.eb(x, y);
            }

            for(auto [lx, ly] : less)
            {
                cout << "? " << ans[ans.size()-1] << " 2 " << ans[ans.size()-1] << " " << ly << "\n" << flush;

                ll num;
                cin >> num;

                if(num == 2)
                {
                    ans.eb(ly);
                    k = lx;
                    break;
                }
            }
        }

        cout << "! " << xi << " ";
        for(auto a : ans) cout << a << " ";
        cout << '\n' << flush;
    }

    return 0;
}