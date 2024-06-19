#include <bits\stdc++.h>
using namespace std;

main()
{
    int n, array[3][100] = {7}, count = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int day;
        string name, score;
        cin >> day >> name >> score;
        int scoreValue = score[1] - '0';
        if (name == "Bessie"){
            if(score.find("-") == string::npos) array[0][day] += scoreValue;
            else array[0][day] -= scoreValue;
        } else if(name == "Mildred"){
            if(score.find("-") == string::npos) array[1][day] += scoreValue;
            else array[1][day] -= scoreValue;
        } else{
            if(score.find("-") == string::npos) array[2][day] += scoreValue;
            else array[2][day] -= scoreValue;
        }

        return 0;
    }

    for(int i = 0; i < 100; i++)
    {
        int lead = 0;
        int highest = max(max(array[0][i], array[1][i]), array[2][i]);
    }
}