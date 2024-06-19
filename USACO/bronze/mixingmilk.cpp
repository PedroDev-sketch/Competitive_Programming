#include <bits\stdc++.h>
using namespace std;

int main()
{
    int c1, m1, c2, m2, c3, m3, counter = 0;
    cin >> c1 >> m1;
    cin >> c2 >> m2;
    cin >> c3 >> m3;

    int i = 1;
    while(counter < 100)
    {
        if(i == 1)
        {
            int pour = min(m1, c2 - m2);
            m1 -= pour;
            m2 += pour;
        }

        else if(i == 2)
        {
            int pour = min(m2, c3 - m3);
            m2 -= pour;
            m3 += pour;
        }

        else if(i == 3)
        {
            int pour = min(m3, c1 - m1);
            m3 -= pour;
            m1 += pour;
        }

        counter++;
        i++;
        if(i >= 4) i = 1;
    }

    cout << m1 << endl << m2 << endl << m3 << endl;

    return 0;
}