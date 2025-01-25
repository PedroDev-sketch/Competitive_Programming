#include <bits\stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if(n > 2)
        {
            cout << "NO" << endl;
            continue;
        }

        else
        {
            if(arr[1] - arr[0] > 1)
            {
                cout << "YES" << endl;
            }

            else
            {
                cout << "NO" << endl;
            }

        }

    }

    return 0;
}