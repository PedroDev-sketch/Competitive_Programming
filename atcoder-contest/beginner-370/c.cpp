#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    vector<string> x;
    int n = s.size();

    while(s != t)
    {
        string nxt(n, 'z');
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
            {
                string tmp = s;
                tmp[i] = t[i];
                nxt = min(nxt, tmp);
            }
        }
        x.push_back(nxt);
        s = nxt;
    }

    int sz = x.size(), k = 0;
    cout << sz << endl;

    while(sz--)
    {
        cout << x[k] << endl;
        k++;
    }

    return 0;
}