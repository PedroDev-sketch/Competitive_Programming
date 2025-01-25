#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 

ll moves(ll num)
{
    ll total = 0;
    while(num)
    {
        total += num;
        num--;
    }
    return total;
}

signed main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    ll n, m, a;
    vll sto, val;
    vpll stones;
    cin >> n >> m;
    for(ll i = 0; i < m; i++)
    {
        cin >> a;
        sto.push_back(a);
    }
    for(ll i = 0; i < m; i++)
    {
        cin >> a;
        val.push_back(a);
    }

    for(ll i = 0; i < m; i++)
    {
        stones.push_back(make_pair(sto[i], val[i]));
    }
    sort(stones.begin(), stones.end());

    if(stones[0].x != 1){ cout << -1 << '\n'; return 0;}


    if(m == 1)
    {
        if(stones[0].y < n) cout << -1 << '\n';
        else cout << moves(n) << '\n';
        return 0;
    }

    ll count = 0, carryover = 0;
    for(ll i = 1; i < m; i++)
    {
        ll diff = (stones[i].x - stones[i-1].x);
        if(diff > stones[i-1].y+carryover)
        {
            cout << -1 << '\n';
            return 0;
        }
        else
        {
            if(diff > stones[i-1].y) carryover -= (diff - stones[i-1].y);
            else carryover += stones[i-1].y - diff;
            count += moves((diff-1));
            if(carryover) count += (diff*carryover);
        }
    }

    ll diff = (n - stones.back().x);
    if(stones.back().y + carryover > diff + 1)
    {
        cout << -1 << '\n';
        return 0;
    }
    else count += moves(diff);

    cout << count << '\n';

    return 0;
}