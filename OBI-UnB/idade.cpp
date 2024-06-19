#include <bits\stdc++.h>
using namespace std;

int main()
{
    int m, a, b;
    cin >> m >> a >> b;
    cout << (((m - a - b) > a && (m - a - b) > b) ? (m - a - b) : (a > b ? a : b));

    return 0;
}