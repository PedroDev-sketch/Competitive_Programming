#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    int a = sqrt((arr[0]*arr[2])/arr[1]);
    int b = sqrt((arr[0]*arr[1])/arr[2]);
    int c = sqrt((arr[1]*arr[2])/arr[0]);
    cout << 4*(a+b+c) << '\n';


    return 0;
}