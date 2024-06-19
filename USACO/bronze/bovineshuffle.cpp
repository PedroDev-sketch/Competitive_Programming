#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> order(n), id(n);
    map<int, int> identify; 

    for(int i = 0; i < n; i++)
    {
        cin >> order[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> id[i];
        identify[order[i]] = id[i];
    }

    for(int key = 1; key <= n; key++)
    {
        cout << identify[key] << endl;
    }

    return 0;
}