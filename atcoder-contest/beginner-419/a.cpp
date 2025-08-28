#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);

    string s;
    cin >> s;

    if(s == "red") cout << "SSS";
    else if(s == "blue") cout << "FFF";
    else if(s == "green") cout << "MMM";
    else cout << "Unknown";
    cout << '\n';

    return 0;
}