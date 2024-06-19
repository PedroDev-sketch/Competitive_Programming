#include <bits\stdc++.h>
using namespace std;

int main()
{
    int l, c, t1 = 0, t2 = 0;
    cin >> l >> c;
    t1 = (l * c) + ((l - 1) * (c - 1));
    t2 += ((c - 1) * 2) + ((l - 1) * 2);
    cout << t1  << endl << t2 << endl;

    return 0;
}