#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define MAXN (1e9 + 7)
#define ff first
#define ss second

void solve()
{
    ll n, q; cin >> n >> q;
    string s; cin >> s; 

    vll ys; ll num = 0;
    bool good = false;
    for(auto x : s)
    {
        if(x=='B')
        {
            good = true;
            if(num) ys.eb(num); num = 0;
            ys.eb(-1);
        }
        else num++;
    }

    if(num) ys.eb(num);

    /* for(auto y : ys) cout << y << ' ';
    cout << '\n'; */

    while(q--)
    {
        ll x; cin >> x;

        if(!good)
        {
            cout << x << '\n';
        }
        else
        {
            ll ans = 0;
            while(x>0)
            {
                for(auto y : ys)
                {
                    if(y==-1)
                    {
                        x/=2;
                        ans++;
                    }
                    else
                    {
                        if(x <= y)
                        {
                            ans += x;
                            x = 0;
                        }
                        else
                        {
                            x-=y;
                            ans+=y;
                        }
                    }

                    if(x <= 0) break;
                }
            }

            cout << ans << '\n';
        }
    }

}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
