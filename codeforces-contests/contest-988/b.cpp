#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second

signed main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        vector<int> sto(n);

        for(int i = 0; i < n; i++)
        {
            cin >> sto[i];
        }

        n -= 2;
        sort(sto.begin(), sto.end());

        int comp;
        for(int i = 0; i < sto.size(); i++)
        {
            if(n % sto[i] == 0)
            {
                comp = n/sto[i];
                if(binary_search(sto.begin(), sto.end(), comp))
                {
                    cout << sto[i] << " " << comp << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}