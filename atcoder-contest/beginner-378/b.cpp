#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
#define x first
#define y second

int main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    ll n, q;
    vector<pll> type, query;
    cin >> n;

    ll a, b;
    for(ll i = 0; i < n; i++)
    {
        cin >> a >> b;
        type.push_back(make_pair(a, b));
    }

    cin >> q;  
    for(ll i = 0; i < q; i++)
    {
        cin >> a >> b;
        query.push_back(make_pair(a, b));
    }  

    for(ll i = 0; i < q; i++)
    {
        ll day = query[i].y;
        /* if(day % (type[query[i].x - 1].x) == type[query[i].x - 1].y)
        {
            break;
        } */
        ll div = day / (type[query[i].x - 1].x);
        ll comp = day % (type[query[i].x - 1].x);

        ll mult = comp <= type[query[i].x - 1].y ? div : div+1;
        ll ans = mult *  type[query[i].x - 1].x + type[query[i].x - 1].y;
        cout << ans << '\n';
    }

    return 0;
}