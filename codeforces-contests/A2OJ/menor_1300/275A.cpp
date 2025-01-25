#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    vector<vector<int>> arr(3, vector<int> (3, 1));
    vector<vector<int>> moves(3, vector<int> (3));

    for(int i = 0; i < 3; i++)
    {
        cin >> moves[i][0] >> moves[i][1] >> moves[i][2];
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(moves[i][j] > 0)
            {
                if(!i && !j)
                {
                    while(moves[i][j]--)
                    {
                        arr[i][j] = 1 - arr[i][j];
                        arr[i][j+1] = 1 - arr[i][j+1];
                        arr[i+1][j] = 1 - arr[i+1][j];
                    }
                }

                else if(!i && j == 1)
                {
                    while(moves[i][j]--)
                    {
                        arr[i][j] = 1 - arr[i][j];
                        arr[i][j+1] = 1 - arr[i][j+1];
                        arr[i][j-1] = 1 - arr[i][j-1];
                        arr[i+1][j] = 1 - arr[i+1][j];

                    }
                }

                else if(!i && j == 2)
                {
                    while(moves[i][j]--)
                    {
                        arr[i][j] = 1 - arr[i][j];
                        arr[i][j-1] = 1 - arr[i][j-1];
                        arr[i+1][j] = 1 - arr[i+1][j];

                    }
                }

                else if(i == 1 && !j)
                {
                    while(moves[i][j]--)
                    {
                        arr[i][j] = 1 - arr[i][j];
                        arr[i-1][j] = 1 - arr[i-1][j];
                        arr[i][j+1] = 1 - arr[i][j+1];
                        arr[i+1][j] = 1 - arr[i+1][j];

                    }
                }

                else if(i == 1 && j == 1)
                {
                    while(moves[i][j]--)
                    {
                        arr[i][j] = 1 - arr[i][j];
                        arr[i-1][j] = 1 - arr[i-1][j];
                        arr[i][j-1] = 1 - arr[i][j-1];
                        arr[i][j+1] = 1 - arr[i][j+1];
                        arr[i+1][j] = 1 - arr[i+1][j];

                    }
                }

                else if(i == 1 && j == 2)
                {
                    while(moves[i][j]--)
                    {
                        arr[i][j] = 1 - arr[i][j];
                        arr[i-1][j] = 1 - arr[i-1][j];
                        arr[i][j-1] = 1 - arr[i][j-1];
                        arr[i+1][j] = 1 - arr[i+1][j];
                    }
                }

                else if(i == 2 && !j)
                {
                    while(moves[i][j]--)
                    {
                        arr[i][j] = 1 - arr[i][j];
                        arr[i-1][j] = 1 - arr[i-1][j];
                        arr[i][j+1] = 1 - arr[i][j+1];
                    }
                }

                else if(i == 2 && j == 1)
                {
                    while(moves[i][j]--)
                    {
                        arr[i][j] = 1 - arr[i][j];
                        arr[i-1][j] = 1 - arr[i-1][j];
                        arr[i][j-1] = 1 - arr[i][j-1];
                        arr[i][j+1] = 1 - arr[i][j+1];
                    }
                }

                else if(i == 2 && j == 2)
                {
                    while(moves[i][j]--)
                    {
                        arr[i][j] = 1 - arr[i][j];
                        arr[i-1][j] = 1 - arr[i-1][j];
                        arr[i][j-1] = 1 - arr[i][j-1];
                    }
                }
            }
        }
    }

    string fi = "", se = "", th = "";

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            char proxy = arr[i][j] + '0';
            if(!i) fi.push_back(proxy);
            else if(i == 1) se.push_back(proxy);
            else th.push_back(proxy);
        }
    }
    cout << fi << '\n';
    cout << se << '\n';
    cout << th << '\n';

    return 0;
}