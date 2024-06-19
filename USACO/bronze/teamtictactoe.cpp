#include <bits\stdc++.h>
using namespace std;

int main()
{
    char array[3][3];
    int solo = 0, team = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> array[i][j];
        }
    }

    for(int i = 0; i < 3; i++)
    {
        int alphabet[26] = { };
        for(int j = 0; j < 3; j++)
        {
            alphabet[array[i][j] - 97]++;
        }

        for(int j = 0; j < 26; j++)
        {
            if(alphabet[j] == 2) team++;
            else if (alphabet[j] == 3) solo++;
        }
    }

    for(int i = 0; i < 3; i++)
    {
        int alphabet[26] = { };
        for(int j = 0; j < 3; j++)
        {
            alphabet[array[j][i] - 97]++;
        }

        for(int j = 0; j < 26; j++)
        {
            if(alphabet[j] == 2) team++;
            else if (alphabet[j] == 3) solo++;
        }
    }

    for(int i = 0; i < 2; i++)
    {
        int alphabet[26] = { };

        if(!i)
        {
            for(int j = 0, z = 0; j < 3; j++, z++)
            {
                alphabet[array[z][j] - 97]++;
            }
        }
        
        else if(i)
        {
            for(int j = 2, z = 0; j >= 0; j--, z++)
            {
                alphabet[array[z][j] - 97]++;
            }
        }

        for(int j = 0; j < 26; j++)
        {
            if(alphabet[j] == 2) team++;
            else if (alphabet[j] == 3) solo++;
        }
    }

    cout << solo << endl << team << endl;

    return 0;
}