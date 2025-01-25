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
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    int q;
    vector<int> flowers;
    cin >> q;

    for(int i = 0; i < q; i++)
    {
        int qtype, qmeasure, count = 0;
        cin >> qtype;

        if(qtype != 1) cin >> qmeasure;
        else
        {
            flowers.push_back(0);
            continue;
        }

        if(qtype == 2)
        {
            for(int j = 0; j < flowers.size(); j++)
            {
                flowers[j]+=qmeasure;
            }
        }

        else
        {
            for(int j = 0; j < flowers.size(); j++)
            {
                if(flowers[j] >= qmeasure) {auto it = find(flowers.begin(), flowers.end(), flowers[j]);flowers.erase(it); j--; count++;}
            }
            cout << count << '\n';
        }
    }

    return 0;
}