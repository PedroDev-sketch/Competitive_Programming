#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
const int MAXN = 100010;
#define x first
#define y second

set<pair<int,int>> taken;

void check(int a, int b, ll n)
{
    taken.insert(make_pair(a, b));
    if((a + 2) < n && (b+1) < n) 
    {
        taken.insert(make_pair(a+2, b+1));
    }
    if((a + 1) < n && (b+2) < n)
    {
        taken.insert(make_pair(a+1, b+2));
    }
    if((a - 1) >= 0 && (b+2) < n) 
    {
        taken.insert(make_pair(a-1, b+2));
    }
    if((a - 2) >= 0 && (b+1) < n)
    {
        taken.insert(make_pair(a-2, b+1));
    }
    if((a - 2) >= 0 && (b-1) >= 0)
    {
        taken.insert(make_pair(a-2, b-1));
    }
    if((a - 1) >= 0 && (b-2) >= 0)
    {
        taken.insert(make_pair(a-1, b-2));
    }
    if((a + 1) < n && (b-2) >= 0)
    {
        taken.insert(make_pair(a+1, b-2));
    }
    if((a + 2) < n && (b-1) >= 0)
    {
        taken.insert(make_pair(a+2, b-1));
    }
    return;
}

int main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    ll total = n*n;


    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--, b--;
        check(a, b, n);
    }

    cout << (total - taken.size()) << '\n';

    return 0;
}