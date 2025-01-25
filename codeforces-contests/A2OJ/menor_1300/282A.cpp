#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        if(s[0] == '+' || s.back() == '+')
        {
            count++;
        }
        else count--;
    }

    cout << count << '\n';


    return 0;
}