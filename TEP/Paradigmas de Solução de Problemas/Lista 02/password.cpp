#include <bits/stdc++.h>
using namespace std;

void generateCombinations(const vector<string>& words, vector<string>& current, int depth, int maxDepth, vector<string>& storageroom) {
    if (depth == maxDepth) 
    {
        string interface;
        for (const auto& word : current) 
        {
            interface +=word;
        }
        storageroom.push_back(interface);
        return;
    }

    for (const auto& word : words) 
    {
        current[depth] = word;
        generateCombinations(words, current, depth + 1, maxDepth, storageroom);
    }
}

signed main()
{
    int dictnum;
    while(cin >> dictnum)
    {
        vector<string> dict(dictnum);
        for(auto& p : dict) cin >> p;

        int rulesnum;
        cin >> rulesnum;
        vector<string> rules(rulesnum);
        for(auto& p : rules) cin >> p;

        for(auto p : rules)
        {
            vector<string> storageroom;
            cout << "--\n";
            int hashtag = 0, num = 0;
            for(auto e : p)
            {
                if(e == '#') hashtag++;
                else num++;
            }

            string base = "", carry = "";
            for(int i = 0; i < num; i++) {base += '1'; carry += '0';}
            int numbase = stoi(base);

            vector<string> current(hashtag);
            generateCombinations(dict, current, 0, hashtag, storageroom);

            for(int i = 0; i < storageroom.size(); i++)
            {
                
                for(int j = 0; j < 9*numbase; j++)
                {
                    int wordindex = 0, numindex = 0;

                    string strj = to_string(j);

                    int ind = carry.size()-1;
                    for(auto x : strj)
                    {
                        carry[ind] = x;
                        ind--;
                    }

                    for(auto e : p)
                    {
                        if(e == '#')
                        {
                            cout << storageroom[i][wordindex];
                            wordindex++;
                        }
                        else if(e == '0')
                        {
                            cout << carry[numindex];
                            numindex++;
                        }
                    }
                }


            }
        }
    }

    return 0;
}