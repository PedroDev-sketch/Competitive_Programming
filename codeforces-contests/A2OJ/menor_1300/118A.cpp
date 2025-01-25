#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
    string s;
    cin >> s;

    for(auto x : s)
    {
        if(x < 'a') {x -= 'A'; x+= 'a';}
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||x == 'y');
        else cout << '.' << x;
    }
    cout << '\n';

    return 0;
}