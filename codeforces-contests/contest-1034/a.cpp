#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> nums(4);

        for(int i = 0; i < n; i++) nums[i%4]++;

        bool ans = false;
        if(nums[0] == nums[3] && nums[1] == nums[2]) ans = true;

        cout << (ans ? "Bob" : "Alice") << '\n';
    }

    return 0;
}