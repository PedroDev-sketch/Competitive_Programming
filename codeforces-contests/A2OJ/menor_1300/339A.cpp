#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

signed main()
{
    fio;
    
    string s;
    cin >> s;

    vll ans;

    for(auto x : s)
    {
        if(x >= '1' && x <= '9')
        {
            ans.eb(x-'0');
        }
    }

    sort(all(ans));

    cout << ans[0];
    for(int i = 1; i < ans.size(); i++)
    {
        cout << "+" << ans[i];
    }
    cout << '\n';

    return 0;
}