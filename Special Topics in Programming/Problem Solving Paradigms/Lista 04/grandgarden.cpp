#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, count = 0;
    cin >> n;

    vector<int> nums(n);
    for(auto& p : nums) cin >> p;

    int l = 0, r = 0, small = 1e7;
    bool end = true;
    while(end)
    {
        end = false;
        l = 0;
        r = 0;
        small = 1e7;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 0) small = min(small, nums[i]);

            if(r == n-1 || nums[i] == 0)
            {
                bool done = false;
                for(int j = l; j <= r; j++)
                {
                    if(nums[j] != 0 && nums[j] - small >= 0) {nums[j] -= small; done = true;}
                }

                if(done) count+=small;

                small = 1e7;
                l = r+1;
            }
            r++;
        }
        /* for(auto p : nums) cout << p << " ";
        cout << endl; */

        for(auto p : nums) if(p != 0) end = true;
    }

    cout <<  count << '\n';

    return 0;
}