#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;

#define all(xs) xs.begin(), xs.end()
#define x first 
#define y second 
#define int ll

#define out cyl.front()

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);
    int q;
    cin >> q;

    queue<pll> cyl;

    while(q--)
    {
        int num;
        cin >> num;

        int a, c;

        if(num == 1)
        {
            cin >> a >> c;
            cyl.push(make_pair(a, c));
        }
        else
        {
            cin >> c;
            int total = 0;

            while(c)
            {
                if(out.y > c)
                {
                    total += out.x * c;
                    out.y -= c;
                    c = 0;
                }
                else if(out.y == c)
                {
                    total += out.x * c;
                    c=0;
                    cyl.pop();
                }
                else
                {
                    total += out.y * out.x;
                    c -= out.y;
                    cyl.pop();
                }
            }
            cout << total << '\n';
        }
    }
    
    
    
    return 0;
}