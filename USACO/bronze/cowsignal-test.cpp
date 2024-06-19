#include <bits\stdc++.h>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> call(m, vector<int> (n));
    vector<vector<int>> callK(m * k, vector<int> (n * k));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> call[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int ki = 0; ki < k; ki++)
            {
                for(int kj = 0; kj < k; kj++)
                {
                    callK[i*k + ki][j*k + kj] = call[i][j];
                }
            }
        }
    }

    for(int i = 0; i < m * k; i++)
    {
        for(int j = 0; j < n * k; j++)
        {
            cout << callK[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}