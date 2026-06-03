#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;

#define all(xs) xs.begin(), xs.end()
#define x first 
#define y second 
#define int ll

#define out cyl.front()

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n, x, y;
    
    cin >> n >> x >> y;
    vll nums(n);

    for(auto& p : nums) cin >> p;

    int l = 0, r = 0;

    int count = 0;
    while(r <= n && l <= r)
    {

        if(!(nums[l] <= x && nums[l] >= y))
        {
            l++;
            r=l;
        }

        if(nums[l] <= x && nums[r] >= y) count++;
        else if(nums[l] >= y && nums[r] <= x) count++;

        r++;
        
    }

    cout << count << '\n';
    
    return 0;
}