#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back
#define int ll

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    int matrix[n][m];
    int tmatrix[m][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];

            tmatrix[j][i] = matrix[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << tmatrix[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}