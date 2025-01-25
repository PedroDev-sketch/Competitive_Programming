#include <bits\stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int k = 0; k < t; k++)
    {
        string n;
        cin >> n;
        int sum = 0;

        for(char c : n)
        {
            sum += c - '0';  
        }

        cout << sum << endl;
    }

    return 0;
}
