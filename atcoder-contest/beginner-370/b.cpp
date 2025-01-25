#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    int counter = 1;

    for(int j = 1; j <= n; j++)
    {
        if(counter >= j) counter = arr[counter-1][j-1];
        else counter = arr[j-1][counter-1];
    }

    cout << counter << endl;

    return 0;
}