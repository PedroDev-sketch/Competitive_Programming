#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> p, q;
    int pi, qi;

    for(int i = 0; i < n; i++)
    {
        cin >> pi;
        p.push_back(pi);
    }

    for(int i = 0; i < n; i++)
    {
        cin >> qi;
        q.push_back(qi);
    }

    vector<pair<int,int>> pq;

    for(int i = 0; i < n; i++)
    {
        pq.emplace_back(q[i], p[i]);
    }

    sort(pq.begin(), pq.end());

    for(auto o : pq)
    {/* 
        cout << o.first << " " << o.second;
        cout << '\n';
 */
        cout << q[o.second-1] << " ";
    }
    cout << '\n';

    return 0;
}