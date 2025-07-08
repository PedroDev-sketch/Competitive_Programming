#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

bool comparafi(const string &a, const string &b) {
    bool a_digit = isdigit(a[0]);
    bool b_digit = isdigit(b[0]);
    
    if (a_digit != b_digit) {
        return b_digit;
    }
    return a < b;
}

void backtracking(vector<string> &dict, string &rule, string output, int start, vector<string> &outputline)
{
    if (start == rule.size())
    {
        outputline.push_back(output);
        return;
    }

    if (rule[start] == '#')
    {
        for (auto e : dict)
        {
            backtracking(dict, rule, output + e, start + 1, outputline);
        }
    }

    if (rule[start] == '0')
    {
        for (int j = 0; j <= 9; j++)
        {
            backtracking(dict, rule, output + to_string(j), start + 1, outputline);
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

        sort(all(dict), comparafi);

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