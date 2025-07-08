#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

void backtracking(vector<string> &dict, string &rule, string output, int start, vector<string> &outputline, string currword = "")
{
    if (start == rule.size())
    {
        outputline.push_back(output);
        return;
    }

    if (rule[start] == '#')
    {
        if(currword.empty())
            for (auto e : dict)
                backtracking(dict, rule, output + e, start + 1, outputline, e);
        else
            backtracking(dict, rule, output + currword, start + 1, outputline, currword);
    }

    if (rule[start] == '0')
    {
        for (int j = 0; j <= 9; j++)
        {
            backtracking(dict, rule, output + to_string(j), start + 1, outputline, currword);
        }
    }

    return;
}

signed main()
{
    int dictnum;
    while (cin >> dictnum)
    {
        vector<string> dict(dictnum);
        for (auto &p : dict)
            cin >> p;

        sort(all(dict));

        int rulesnum;
        cin >> rulesnum;
        vector<string> rules(rulesnum);
        for (auto &p : rules)
            cin >> p;

        for (auto p : rules)
        {
            cout << "--\n";
            vector<string> outputline;
            backtracking(dict, p, "", 0, outputline);

            for (auto e : outputline)
                cout << e << '\n';
        }
    }

    return 0;
}