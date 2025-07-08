#include <bits/stdc++.h>
using namespace std;

#define x first 
#define y second
#define all(xs) xs.begin(), xs.end()

#define int long long

signed main()
{
    int n, h, counter = 0;
    cin >> n >> h;

    vector<int> lista;

    int ma = -1;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        ma = max(a, ma);

        lista.push_back(b);
    }

    sort(all(lista), greater<int>());

    for(auto& p : lista)
    {
        if(p > ma)
        {
            h -= p;
            counter++;
        }

        if(h <= 0)
        {
            cout << counter << '\n';
            return 0;
        }
    }

    int r = ceil((double)h/ma);
    counter += r;
    
    cout << counter << '\n';
    return 0;
}