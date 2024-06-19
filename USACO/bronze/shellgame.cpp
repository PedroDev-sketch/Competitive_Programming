#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> shells(3), counter(3);

    for(int i = 0; i < 3; i++) 
    { 
        shells[i] = i; 
    }

    for(int i = 0; i < n; i++)
    {
        int a, b, g;
        cin >> a >> b >> g;
        a--, b--, g--;

        swap(shells[a], shells[b]);
        counter[shells[g]]++;
    }

    cout << max({counter[0], counter[1], counter[2]});

    return 0;
}