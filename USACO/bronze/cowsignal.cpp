#include <bits\stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<char>> call(m, vector<char> (n));

    vector<vector<char>> callK(m * k, vector<char> (n * k));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> call[i][j];
        }
    }

    int x = 0, y = 0;

    for(int i = 0; i < m * k; i++)
    {

        for(int j = 0; j < n * k; j++)
        {
            for(int z = 0; z < k; z++)
            {
                callK[i][j + z] = call[x][y];
            }

            j += k - 1;
            y++;
        }

        for(int j = 0; j < n * k; j++)
        {
            for(int z = 0; z < k; z++)
            {
                callK[i + z][j] = callK[i][j];
            }
        }

        i += k - 1;
        x++;
        y = 0;
    }

    for(int i = 0; i < m * k; i++)
    {
        for(int j = 0; j < n * k; j++)
        {
            cout << callK[i][j];
        }
        cout << endl;
    }

    return 0;
}