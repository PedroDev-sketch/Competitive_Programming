#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, x;
    cin >> n >> x;

    vector<int> friends(n);
    for(auto& p : friends) cin >> p;

    set<int> xs;

    int newfriend = x;

    while(true)
    {
        int size = xs.size();
        xs.insert(newfriend);

        int newsize = xs.size();
        if(size == newsize) break;

        newfriend = friends[newfriend-1];
    }

    cout << xs.size() << '\n';
}