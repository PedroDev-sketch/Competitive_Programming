#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
const int MAXN = int(1e5 +10);

int main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    ll n, m, num;
    cin >> n;
    vll arr(MAXN);
    for(ll i = 0; i < n; i++)
    {
        cin >> num;
        arr[num] = i+1;
    }

    ll ans1 = 0, ans2 = 0;
    cin >> m;
    for(ll i = 0; i < m; i++)
    {
        cin >> num;
        ans1 += arr[num];
        ans2 += n - arr[num] +1;
    }
    
    cout << ans1 << " " << ans2 << '\n';

    return 0;
}