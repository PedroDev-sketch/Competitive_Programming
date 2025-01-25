#include <bits\stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int ans = 0;
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        vector<pair<int, int>> suneet = {{a1, a2}, {a1, a2}, {a2, a1}, {a2, a1}};
        vector<pair<int, int>> slavic = {{b1, b2}, {b2, b1}, {b1, b2}, {b2, b1}};

        int suneetWins = 0;

        for (int i = 0; i < 4; ++i) {
            int sWins = 0, lWins = 0;

            if (suneet[i].first > slavic[i].first) ++sWins;
            else if (suneet[i].first < slavic[i].first) ++lWins;

            if (suneet[i].second > slavic[i].second) ++sWins;
            else if (suneet[i].second < slavic[i].second) ++lWins;

            if (sWins > lWins) ++suneetWins;
        }

        cout << suneetWins << endl;
    }

    return 0;
}