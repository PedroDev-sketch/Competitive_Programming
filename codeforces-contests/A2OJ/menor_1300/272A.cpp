#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n, count = 0, ans = 5;
    cin >> n;
    vector<int> comp = {1, 2, 3, 4, 5};

    for(int i = 0; i < n; i++)
    {
        int fingers;
        cin >> fingers;
        count += fingers;
    }
    n+=1;

    for(int i = 0; i < comp.size(); i++)
    {
        if(((count + comp[i]) % n) == 1) ans--;
    }

    cout << ans << '\n';

    return 0;
}