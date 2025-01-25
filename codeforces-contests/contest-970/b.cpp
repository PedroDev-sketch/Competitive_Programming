#include <bits\stdc++.h>
using namespace std;

bool hasRoot(int num)
{
    double root = sqrt(num);
    int intRoot = static_cast<int>(root);
    return (root == static_cast<double>(intRoot));
}

int main()
{
    int t, len, square, count;
    string bin;
    cin >> t;
    while(t--)
    {
        cin >> len;
        cin >> bin;
        count = 0;
        
        if(hasRoot(len))
        {
            square = sqrt(len);
            for(int i = square+1; i <= (square)*(square-2)+1; i+=square)
            {
                for(int j = i; j < i+(square-2); j++)
                {
                    if(bin[i] == '0') count++;
                }
            }
        }
        else
        {
            cout << "No" << endl;
            continue;
        }
        if(square == 2)
        {
            cout << "Yes" << endl;
            continue;
        }

        int ideal = pow((square - 2), 2);

        /* cout << count << " " << ideal << " " << square << endl; */

        if(count == ideal) cout << "Yes" << endl;
        else cout << "No" << endl;
        continue;
    }

    return 0;
}