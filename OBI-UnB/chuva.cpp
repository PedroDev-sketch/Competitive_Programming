#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char parede[n][m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> parede[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(parede[i-1][j] == 'o' || (parede[i][j-1] == 'o' && parede[i+1][j-1] == '#') || (parede[i][j+1] == 'o' && parede[i+1][j+1] == '#'))
            {
                parede[i][j] = 'o';
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << parede[i][j] ;
        }
        cout << endl;
    }

    return 0;
}