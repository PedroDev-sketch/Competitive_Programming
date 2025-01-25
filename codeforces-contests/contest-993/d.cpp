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
    cin.tie(0) -> ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        map<int,int>occ;
        for(int i = 1; i<=n;i++)
        {
            occ[i] = 1;
        }

        
        
        vector<int> a(n), b(n, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(occ.count(a[i]))
            {
                b[i] = a[i];
                occ.erase(a[i]);
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(b[i] == 0)
            {
                b[i] = (*occ.begin()).x;
                occ.erase(occ.begin());
            }
        }

       for(int i =0 ; i< n; i++)
       {
            cout << b[i] << (i+1 == n ? "\n" : " ");
       }
    }

    return 0;
}