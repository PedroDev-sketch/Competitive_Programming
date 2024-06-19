#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int arrC[13] = {0}, arrE[13] = {0}, arrU[13] = {0}, arrP[13] = {0}, num, count[4] = {0};
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == 'C')
        {
            num = ((input[i - 2] - '0')*10 + (input[i - 1] - '0'));
            arrC[num - 1]++;
        }
        else if(input[i] == 'E')
        {
            num = ((input[i - 2] - '0')*10 + (input[i - 1] - '0'));
            arrE[num - 1]++;
        }
        else if(input[i] == 'U')
        {
            num = ((input[i - 2] - '0')*10 + (input[i - 1] - '0'));
            arrU[num - 1]++;
        }
        else if(input[i] == 'P')
        {
            num = ((input[i - 2] - '0')*10 + (input[i - 1] - '0'));
            arrP[num - 1]++;
        }
    }

    for(int i = 0; i < 13; i++)
    {
        if(arrC[i] == 0) count[0]++;
        else if(arrC[i] > 1) count[0] = 10000;
        if(arrE[i] == 0) count[1]++;
        else if(arrE[i] > 1) count[1] = 10000;
        if(arrU[i] == 0) count[2]++;
        else if(arrU[i] > 1) count[2] = 10000;
        if(arrP[i] == 0) count[3]++;
        else if(arrP[i] > 1) count[3] = 10000;
    }

    for(int i = 0; i < 4; i++)
    {
        if(count[i] >= 10000) cout << "erro" << endl;
        else cout << count[i] << endl;
    }

    return 0;
}