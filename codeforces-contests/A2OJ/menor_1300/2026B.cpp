#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main()
{
    ios::sync_with_stdio(false);

    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vll arr;
        ll a, big_gap = -1, sec_gap = -1;

        for(int i = 0; i < n; i++)
        {
            cin >> a;
            arr.push_back(a);
        }

        if(n == 1)
        {
            cout << 1 << '\n';
            continue;
        }

        for(int i = 0; i < n-1; i+=2)
        {
            big_gap = max(big_gap, (arr[i+1] - arr[i]));
        }

        if(!(n%2))
        {
            cout << big_gap << '\n';
            continue;
        }

        big_gap = 1e18;
 
        for (ll i = 0; i < n; i += 2) {
            ll gap = 1;
            for (int j = 0; j < i - 1; j += 2) gap = max(gap, arr[j + 1] - arr[j]);
            for (int j = i + 1; j < n; j += 2) gap = max(gap, arr[j + 1] - arr[j]);
            big_gap = min(big_gap, gap);
        }
        cout << big_gap << '\n';

    }

    return 0;
}