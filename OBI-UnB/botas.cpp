#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    int m[n];
    char l[n];
    int ans[31] = {0};

    for(int i = 0; i < n; i++)
    {
        cin >> m[i] >> l[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(l[i] == 'D') ans[m[i] - 30]++;
        else if(l[i] == 'E') ans[m[i] - 30]+= 2;
    }

    for(int i = 0; i < 31; i++)
    {
        if(ans[i] == 3) count++;
    }

    cout << count << endl;

    return 0;
}