#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
const int MAXN = 100010;
#define x first
#define y second

int main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    vector<string> mapa(8);
    vector<int> ri, rj;
    string s;
    int count = 0;

    for(int i = 0; i < 8; i++)
    {
        cin >> s;
        mapa[i] = s;
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(mapa[i][j] == '#')
            {
                ri.push_back(i);
                rj.push_back(j);
            }
        }
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(mapa[i][j] == '.')
            {
                auto iti = find(ri.begin(), ri.end(), i);
                auto itj = find(rj.begin(), rj.end(), j);
                if(iti == ri.end() && itj == rj.end()) count++;
            }
        }
    }

    cout << count << '\n';

    return 0;
}