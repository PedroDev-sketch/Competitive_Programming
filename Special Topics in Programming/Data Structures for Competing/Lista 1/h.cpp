#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    int n, s;
    cin >> n >> s;
    vector<int> xs(n+1);

    xs[0] = s;

    for(int i = 1; i <= n; ++i)
    {
        int num;
        cin >> num;
        s+= num;

        xs[i] = s;
    }

    cout << *min_element(all(xs)) << '\n';
    return 0;
}