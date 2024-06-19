#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n, k, count = 0;
    cin >> n >> k;
    vector <int> x(n);

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int flag = 1;
    int sum = 0, m = 0;
    while(flag)
    {
        while(sum < k)
        {
            sum += x[m];
            m++;
        }

        if(sum == k)
        { 
            count++;

            int counter = 0;
            while(flag)
            {
                for(int i = 0; !i; i++)
                {
                    sum += x[m];
                }

                if(sum == k)
                {
                    count++;
                    m++;
                    counter++;
                }

                else flag = 0;
            }
            flag = 1;
            m -= counter;
        }

        if(sum > k)
        {
            sum = 0;
            if(x[m] > k) m++;
        }

        if(m > n) flag = 0;
    }

    cout << count << endl;

    return 0;
}