#include <bits\stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    size_t pos;
    while((pos = s.find(t)) != string::npos)
    {
        s.erase(s.find(t), t.length());
    }

    cout << s;

    return 0;
}