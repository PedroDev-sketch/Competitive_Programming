#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n%2) cout << -1 << '\n';
    else
    {
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 1);
        for(int i = 1; i < n; i+=2)
        {
            swap(arr[i-1], arr[i]);
        }
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << ((i+1 == n) ? "\n" : " ");
        }
    }


    return 0;
}