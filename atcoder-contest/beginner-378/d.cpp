#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
#define x first
#define y second

void DFS(vector<string>& field, vector<vector<bool>>& visited, int i, int j, int k, int& ans, int k_local)
{
    int h = field.size(), w = field[0].length();
    vector<pair<int,int>> move{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    if(k_local == k)
    {
        ans+=1;
        return;
    }
    visited[i][j] = true;

    for(int n = 0; n < 4; n++)
    {
        int newi = i + move[n].x, newj = j + move[n].y;
        if((newi >= 0 && newi < h) && (newj >= 0 && newj < w) && field[newi][newj] == '.' && !visited[newi][newj]) DFS(field, visited, newi, newj, k, ans, k_local+1);
    }

    visited[i][j] = false;

}

int main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int h, w, k, ans = 0;
    cin >> h >> w >> k;

    vector<string> field;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    for(int i = 0; i < h; i++)
    {
        string s;
        cin >> s;
        field.push_back(s);
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(field[i][j] == '.')
            {
                DFS(field, visited, i, j, k, ans, 0);
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}