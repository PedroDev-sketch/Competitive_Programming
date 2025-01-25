#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 
#define int ll

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int,int>> sn;

    int a, b, head = 0, headsave = 0;
    int rmacc = 0;
    vector<int> rmv;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(a != 2) cin >> b;

        if(a == 1) 
        {
            sn.emplace_back(head, b); 
            head+=b;
            rmv.push_back(rmacc);
        }

        else if(a==2)
        {
            int rm = sn[headsave].y;

            head -= rm;

            rmacc += rm;

            sn[headsave].x = -1;
            sn[headsave].y = -1;
            headsave++;
            
            /* for(int i = 0; i < sn.size(); i++)
            {
                sn[i].x -= rm;
            } */
        }

        else 
        {
            cout << sn[b+headsave-1].x - (rmacc - rmv[b+headsave-1]) << '\n';
        }
    }
    

    return 0;
}