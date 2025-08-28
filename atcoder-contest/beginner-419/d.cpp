#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vll xs(n+1, 0);

    for(int i = 0; i < m; i++)
    {
        ll l, r;
        cin >> l >> r;

        xs[l-1] += 1;
        xs[r] += -1;
    }

    for(int i = 0; i < n; i++) cout << xs[i] << " ";
    cout << '\n';

    for(int i = 0; i < n-1; i++) xs[i+1] += xs[i];

    for(int i = 0; i < n; i++) cout << xs[i] << " ";
    cout << '\n';

    string ans = "";
    for(int i = 0; i < n; i++)
    {
        if(xs[i] % 2 == 0) ans += s[i];
        else ans += t[i];
    }
    

    cout << ans << '\n';

    return 0;
}