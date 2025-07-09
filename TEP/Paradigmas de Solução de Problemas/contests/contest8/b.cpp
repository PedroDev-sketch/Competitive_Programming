#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define all(xs) xs.begin(), xs.end()
#define x first 
#define y second 

signed main()
{
    int n;
    cin >> n;
    
    vector<pair<string,string>> name(n);
    set<string> check;

    for(int i = 0; i < n; i++)
    {
        cin >> name[i].x >> name[i].y;
        check.insert(name[i].x);
        check.insert(name[i].y);
    }

    bool ans = true;
    /* bool s0 = false;
    for(int i = 0; i < n && ans; i++)
    {
        bool one=false, two= false;
        for(int j = 0; j < n; j++)
        {
            if(j!=i)
            {
                if(name[i].x == name[j].x) one = true;
                if(name[i].x == name[j].y) two = true;

                if(name[i].y == name[j].x) one = true;
                if(name[i].y == name[j].y) two = true;
            }
        }

        if(one and two) ans = false;
    } */

    

    cout << ((2*n - check.size() <= 1 )? "Yes" : "No") << '\n';

    

    return 0;
}