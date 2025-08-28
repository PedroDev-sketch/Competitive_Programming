#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    ll q;
    cin >> q;

    multiset<ll> xs;

    while(q--)
    {
        ll t;
        cin >> t;

        if(t == 1)
        {
            ll num;
            cin >> num;

            xs.insert(num);
        }

        else
        {
            auto it = xs.begin();
            cout << *it << '\n';
            xs.erase(it);
        }
    }

    return 0;
}