#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair

signed main()
{   
    fio;

    ll q; cin >> q;
    queue<pll> xs;
    while(q--)
    {
        ll qtype;
        cin >> qtype;

        if(qtype==1)
        {
            ll x, c;
            cin >> x >> c;

            xs.push(mp(c, x));
        }

        else
        {
            ll c;
            cin >> c;

            ll ans = 0;
            while(c && !xs.empty())
            {
                if(xs.front().first > c)
                {
                    ans += c * xs.front().second;
                    xs.front().first-=c;
                    c=0;
                }

                else
                {
                    ans += xs.front().first * xs.front().second;
                    c-=xs.front().first;

                    xs.pop();
                }
            }

            cout << ans << '\n';
        }
    }

    return 0;
}