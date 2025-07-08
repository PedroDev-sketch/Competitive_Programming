#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()
#define int long long 

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> casas(n);
    vector<int> xs(m);

    int sum = 0, avg = 0, counterweight=0;
    for(auto &p : casas) 
    {
        cin >> p; 
        sum += p;

        avg += p*p;
    }

    for(auto& p : xs) cin >> p;

    counterweight = sum*sum;
    avg /= counterweight;

    int low = 1e18, index = -1;
    for(int i = 0; i < m; i++)
    {
        int savelow = low;
        low = min(low, abs(avg - xs[i]));

        if(savelow != low)
        {
            index = i;
        }
    }

    int ans = 0;
    for(auto p : casas)
    {
        ans += abs(p - xs[index]);
    }

    cout << ans << " " << index+1 << '\n';

    return 0;
}