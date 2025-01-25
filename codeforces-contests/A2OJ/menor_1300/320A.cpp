#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string cas = to_string(n);
    bool check = true;
    for(int i = 0; i < cas.length(); i++)
    {
        if(cas[i] == '1' && cas[i+1] == '4' && cas[i+2] == '4') i += 2;
        else if(cas[i] == '1' && cas[i+1] == '4') i++;
        else if(cas[i] == '1');
        else check = false;
    }
    if(check) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}