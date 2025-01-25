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

    int n, d, empty = 0;
    cin >> n >> d;
    string in;

    cin >> in;

    for(int i = n-1; i >= 0; i--)
    {
        if(empty == d) break;

        if(in[i] == '@')
        {
            in[i] = '.';
            empty++;
        }
    }
    cout << in << '\n';

    return 0;
}