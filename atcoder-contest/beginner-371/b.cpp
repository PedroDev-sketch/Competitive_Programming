#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, Nans;
    char Mans;
    cin >> n >> m;
    vector<int> arr(n, 0);
    string babies[m];

    for(int i = 0; i < m; i++)
    {
        cin >> Nans >> Mans;
        if(arr[Nans-1] == 0 && Mans == 'M')
        {
            arr[Nans-1] = 1;
            babies[i] = "Yes";
        }
        else babies[i] = "No";
    }

    for(int i = 0; i < m; i++)
    {
        cout << babies[i] << endl;
    }

    return 0;
}