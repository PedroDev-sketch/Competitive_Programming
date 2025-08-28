#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
#define int ll

#define all(xs) xs.begin(), xs.end()

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    ll m;
    cin >> m;

    while(m--)
    {
        ll n, k;
        cin >> n >> k;

        vll s(n), t(n);
        for(auto& x : s) {cin >> x; x %= k;}
        for(auto& x : t) {cin >> x; x %= k;}

        sort(all(t));

        bool ans = true;

        for(int i = 0; i < n && ans; i++)
        {
            auto it = lower_bound(all(t), s[i]);
            if(it != t.end() && *it == s[i]) t[it - t.begin()] = -1;

            else if (it = lower_bound(all(t), s[i] + k), it != t.end() && *it == s[i] + k) t[it - t.begin()] = -1;

            else if (it = lower_bound(all(t), abs(s[i] - k)), it != t.end() && *it == abs(s[i] - k)) t[it - t.begin()] = -1;
            
            else ans = false;

            sort(all(t));
        }

        for(auto x : t) if(x != -1) {ans = false; break;}

        cout << (ans ? "Yes" : "No") << '\n';
    }

    return 0;
}