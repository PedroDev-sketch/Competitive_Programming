#include <bits\stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int k = 0; k < t; k++)
    {
        int n, count = 0, even = 0, odd = 0;
        cin >> n;
        vector<int> arr(n, 0);

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for(int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0) even++;
            else if (arr[i] % 2 == 1) odd++;
        }

        if(even == n || odd == n)
        {
            cout << 0 << endl;
            continue;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j != i)
                {
                    int stateI = arr[i] % 2, stateJ = arr[j] % 2;
                    if((stateI != stateJ))
                    {
                        if((arr[i] < arr[j]))
                        {
                            count++;
                            arr[i] += arr[j];
                        }

                        else if((arr[i] > arr[j]))
                        {
                            count++;
                            arr[j] += arr[i];
                        }
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}