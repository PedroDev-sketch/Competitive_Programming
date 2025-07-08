#include <bits/stdc++.h>
using namespace std;

int binary_find(int lower, int upper, const int& n, const int& k)
{
    if(upper - lower <= 1) 
    {
        int sum = 0;
        for(int buffer = lower; buffer > 0; buffer /= k) sum += buffer;

        if(sum >= n) return lower;
        return upper;
    }

    int mid = lower + (upper - lower)/2;
    int count = 0;

    for(int buffer = mid; buffer > 0; buffer /= k) count += buffer;

    if(count >= n)
        return binary_find(lower, mid, n, k);
    else
        return binary_find(mid, upper, n, k);

    return 0;
}

signed main()
{
    int n, k;
    cin >> n >> k;

    int upper = 1, lower = 1;
    while(upper < n) upper *= k;

    int ans = binary_find(lower,upper, n, k);
    cout << ans << '\n';

    return 0;
}