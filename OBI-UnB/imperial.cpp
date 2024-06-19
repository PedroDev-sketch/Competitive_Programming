#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1), dp(n+1, 0), cnt(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    dp[1] = cnt[1];
    for(int i=2; i<=n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + cnt[i]);
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
