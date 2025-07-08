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

    int n, m;
    cin >> n >> m;

    //vector<vector<int>> linkedlist(n);
    int count = 0;

    set<pair<int,int>> check;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        if(u == v)
        {
            count++;
            continue;
        }

        int size = check.size();

        check.insert(make_pair(u, v));
        check.insert(make_pair(v, u));

        int newsize = check.size();

        if(size == newsize) count++;

        //linkedlist[u-1].push_back(v-1);
    }

    /* int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(auto p : linkedlist[i])
        {
            if(i == p) count++;
            else if(find(linkedlist[p].begin(), linkedlist[p].end(), i) != linkedlist[p].end()) {count++; cout << i+1 << " " << p+1 << '\n';}
        }
    } */

    cout << count << '\n';

    return 0;
}