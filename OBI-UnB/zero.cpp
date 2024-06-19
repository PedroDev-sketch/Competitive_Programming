#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, total = 0;
    cin >> n;
    vector<int> array(n);

    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for(int i = n-1; i >= 0; i--)
    {
        if(array[i] == 0 && array[i-1] != 0)
        {
            array.erase(array.begin() + i);
            array.erase(array.begin() + (i - 1));
            i = array.size();
        }
    }

    for(int i = 0; i < array.size(); i++)
    {
        total += array[i];
    }

    cout << total << endl;

    return 0;
}