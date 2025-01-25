#include <bits/stdc++.h>
using namespace std;
const int MAXN = 8000;

int main()
{
    ios::sync_with_stdio(false);

    int n, k = 0;
    cin >> n;

    while(k <= MAXN)
    {
        k++;
        n++;

        set<char> test;
        string sn = to_string(n);
        for(auto x : sn)
        {
            test.insert(x);
        }
        if(test.size() == 4)
        {
            cout << n << '\n';
            return 0;
        }
    }
}