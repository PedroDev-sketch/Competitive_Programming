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
        for(auto& x : xs) cin >> x;

        ll op = 0;
        for(int i = 1; i < n; i++)
        {
            if((i+1)%2 == 0)
            {
                if(i-1 >= 0 && xs[i-1]>xs[i]) 
                {
                    ll diff = xs[i-1] - xs[i];
                    op+=diff;
                    xs[i-1] = xs[i];
                }
                if(i+1 < n && xs[i+1]>xs[i]) 
                {
                    ll diff = xs[i+1] - xs[i];
                    op+=diff;
                    xs[i+1] = xs[i];
                }
                if(i+1 < n && i-1 >= 0 && xs[i-1] + xs[i+1] > xs[i])
                {
                    ll outersum = xs[i-1] + xs[i+1];
                    ll remain = outersum - xs[i];

                    op += remain;

                    xs[i+1] -= remain;
                    if(xs[i+1] < 0)
                    {
                        xs[i-1] += xs[i+1];
                        xs[i+1] = 0;
                    }
                }
            }
        }

        cout << op << '\n';
    }

    return 0;
}