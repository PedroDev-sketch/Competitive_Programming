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
    vector<pair<int, string>> total(31);
    set<string> comb;

    for(int bit = 1; bit < 32; bit++)
    {
        string name = "";
        for(int digit = 0; digit < 5; digit++)
        {
            if(bit & 1 << digit) 
            { 
                name += "ABCDE"[digit];
                comb.insert(name);
            }
        }
    }

    int k= 0;
    for(auto it = comb.begin(); it != comb.end(); it++)
    {
        total[k].y = *it;
        k++;
    } 

    vector<pair<int, char>> weigth(5);
    for(int i = 0; i < 5; i++)
    {
        cin >> weigth[i].x;
        weigth[i].y = i + 'A';
    }

    for(int i = 0; i < total.size(); i++)
    {
        int count = 0;
        for(auto p : total[i].y)
        {
            for(int j = 0; j < 5; j++)
            {
                if(p == weigth[j].y) count += weigth[j].x;
            }
        }
        total[i].x = -count;
    }

    sort(total.begin(), total.end());

    for(int i = 0; i < total.size(); i++)
    {
        cout << total[i].y << '\n';
    }

    return 0;
}