#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()
#define N 1048576
#define int long long

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);
    vector<int> A(N, -1);
    set<int> available;
    for(int i = 0; i < N; i++) available.insert(i);

    int q;
    cin >> q;

    int t, x;
    for(int i = 0; i < q; i++)
    {
        cin >> t >> x;

        if(t == 1)
        {
            int h = x;

            auto it = available.lower_bound(h%N);
            if(it == available.end())
            {
                h = *available.begin();
            }
            else if(*it != (h%N)) h = *it;

            A[h%N] = x;
            available.erase(h%N);
        }
        else
        {
            //if(A.find(x%N))
                cout << A[x%N] << '\n';
        }
    }

    //for(int i = 0; i < 100; i++) cout << A[i] << '\n';
    

    return 0;
}