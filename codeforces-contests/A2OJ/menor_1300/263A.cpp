#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> arr(5, vector<int> (5));
    int di, dj;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(arr[i][j] == 1)
            {
                di = i+1;
                dj = j+1;
            }
        }
    }

    cout << (abs(di - 3) + abs(dj - 3)) << endl;


    return 0;
}