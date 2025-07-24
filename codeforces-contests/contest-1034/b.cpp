#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;

#define all(xs) xs.begin(), xs.end()

const int INF = 1e9+7;

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, j, k;
        cin >> n >> j >> k;

        vector<int> xs(n);
        for(auto& x : xs) cin >> x;

        if(xs.size() % 2)
        {
            cout << "Yes\n";
            continue;
        }

        int f = xs[j-1];
        xs[j-1] = INF;

        int f2 = *min_element(all(xs));

        if(f < f2) cout << "No";
        else cout << "Yes";
        cout << '\n';
    }

    return 0;
}