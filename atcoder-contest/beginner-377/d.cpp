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

    int n, m, count = 0;
    cin >> n >> m;

    vector<pair<int,int>> arr;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    int k = 0;
    for(int i = 1; i <= m; i++)
    {
        if(arr[k].x <= (i+1) && arr[k].y <= (i+1));
    }

    return 0;
}