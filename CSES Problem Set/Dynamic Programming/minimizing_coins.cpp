#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solve(vector<int>& coins,  vector<int>& count, int x)
{
    if(x<0) return INF;
    if(x==0) return 0;
    if(count[x]) return count[x];
    int best = INF;

    for(auto c : coins)
    {
        best = min(best, solve(coins, count, x-c)+1);
    }

    count[x] = best;
    return best;
}

signed main()
{
    int n, obj;
    cin >> n >> obj;

    vector<int> coins(n), count(obj+1, 0);
    for(auto& x : coins) cin >> x;

    int ans = solve(coins, count, obj);
    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}