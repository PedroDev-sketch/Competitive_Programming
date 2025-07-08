#include <bits/stdc++.h>
using namespace std;

#define int long long
const int m = 1e9+7;

int die[]{1, 2, 3, 4, 5, 6};

int solve(vector<int>& count, int n)
{
    count[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(auto d : die)
        {
            if(i-d >= 0) {count[i] += count[i-d]; count[i] %= m;}
        }
    }
    return count[n];
}

signed main()
{
    int n;
    cin >> n;

    vector<int> count(n+1, 0);

    int ans = solve(count, n);
    cout << ans << '\n';
    return 0;
}