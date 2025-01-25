#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
#define first x
#define second y

int main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    vector<int> arr(4);
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    sort(arr.begin(), arr.end());

    int comp1 = (arr[0] == arr[1]) + (arr[2] == arr[3]);
    int comp2 = (arr[1] == arr[2]);

    cout << max(comp1, comp2) << '\n';


    return 0;
}