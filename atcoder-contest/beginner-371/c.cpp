#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<pair<int,int>> edgeG, edgeH;

    int mg;
    cin >> mg;
    for(int i = 0; i < mg; i++)
    {
        int u, v;
        cin >> u >> v;
        edgeG.emplace(u-1, v-1);
        edgeG.emplace(v-1, u-1);
    }

    int mh;
    cin >> mh;
    for(int i = 0; i < mh; i++)
    {
        int u, v;
        cin >> u >> v;
        edgeH.emplace(u-1, v-1);
        edgeH.emplace(v-1, u-1);
    }

    vector A(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    int ans{28000000};

    do
    {
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                sum += A[i][j] * (edgeH.count({i, j}) != edgeG.count({p[i], p[j]}));
            }
        }
        ans = min(ans, sum);
    }while(next_permutation(p.begin(), p.end()));

    cout << ans << endl;

    return 0;
}