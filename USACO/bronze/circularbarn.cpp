#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n, dist = 0, answer = 100000;
    cin >> n;
    vector<int> rooms(n);

    for(int i = 0; i < n; i++)
    {
        cin >> rooms[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i==0) dist += rooms[j] * j;
            else 
            {
                if(j < i) dist += rooms[j] * (n - i + j);
                else if(j > i) dist += rooms[j] * (j - i);
            }
        }
        answer = min(answer, dist);
        dist = 0;
    }

    cout << answer << endl;

    return 0;
}