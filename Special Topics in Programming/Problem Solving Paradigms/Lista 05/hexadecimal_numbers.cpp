#include <bits/stdc++.h>
using namespace std;

void backtracking(string source, const string& n, int& count, const int& maxdepth)
{
    if(stoi(source) <= stoi(n))count++;

    if(source.size() == maxdepth)
    {
        return;
    }

    backtracking(source+"1", n, count, maxdepth);
    backtracking(source+"0", n, count, maxdepth);
}

signed main()
{
    string n;
    cin >> n;

    string source = "1";
    int count = 0;

    backtracking(source, n, count, n.size());

    cout << count << '\n';
}