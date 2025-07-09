#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define all(xs) xs.begin(), xs.end()
#define x first 
#define y second 

#define int ll

void solve(vector<char>& ans, int n, int l, int r)
{
    if(n <= 0) return;
    int m = l + (r-l)/2;
    ans[m] = (n+'0');

    solve(ans, n-1, l, m);
    solve(ans, n-1, m+1, r);
}

signed main()
{
    int n;
    cin >> n;
    
    int size = pow(2, n) - 1;
    vector<char> ans(size);
    solve(ans, n, 0, size);

    string out = "";
    for(auto p : ans) {cout << p-'0' << ' ';}

    cout << '\n';
    
    return 0;
}