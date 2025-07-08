#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()
#define int long long

signed main()
{
    int n;
    cin >> n;

    vector<int> cards(n);
    int total = 0;
    for(auto& x : cards)
    {
        cin >> x;
        total+=x;
    }

    int sum = 0, ans = 1e11+7;
    for(int i = 0;i < n; i++)
    {
        sum += cards[i];
        if(i+1 < n) ans = min(ans, abs(total - 2*sum));
    }

    cout << ans << '\n';
    
    return 0;
}