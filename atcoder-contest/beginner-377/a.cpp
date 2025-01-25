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

    string s;
    cin >> s;
    auto ita = find(s.begin(), s.end(), 'A');
    auto itb = find(s.begin(), s.end(), 'B');
    auto itc = find(s.begin(), s.end(), 'C');

    if(ita != s.end() && itb != s.end() && itc != s.end())
    {
        cout << "Yes" << '\n';
    }
    else cout << "No" << '\n';

    return 0;
}