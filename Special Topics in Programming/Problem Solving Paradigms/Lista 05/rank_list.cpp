#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

bool compare(const pair<int,int>& a, const pair<int,int>& b)
{
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> xs(n);
    for(auto& [x, y] : xs) cin >> x >> y;

    sort(all(xs), compare);

    vector<int> anspos, ansval;

    pair<int,int> comp = xs[0];
    int count = 1, savei = 0;
    bool flag = true;

    for(int i = 1; i < n; i++)
    {
        if(xs[i] != comp)
        {
            comp = xs[i];
            anspos.push_back(i);
            ansval.push_back(count);
            count = 1;
            //savei = i+1;
            if(i+1 == n) break;
        }

        if(xs[i-1] == comp) count++;
    }

    if(count) {ansval.push_back(count); anspos.push_back(n);}

    auto it = lower_bound(all(anspos), k);

    /* for(auto p : anspos) cout << p << " ";
    cout << '\n';

    for(auto p : ansval) cout << p << " ";
    cout << '\n'; */
    cout << ansval[it - anspos.begin()]  << '\n';

    return 0;
}