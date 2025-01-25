#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;

#define x first 
#define y second
#define int ll

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n, ans = 0;
    cin >> n;

    vector<int> high;

    int ck;
    for(int i = 0; i < n; i++)
    {
        cin >> ck;

        int j=i;
        while(j>=0 && i != 0)
        {
            if(ck/2 >= high[j])
            {
                ans+=(j+1);
                break;
            }
            j--;
        }
        high.push_back(ck);
    }

    cout << ans << '\n';

    return 0;
}