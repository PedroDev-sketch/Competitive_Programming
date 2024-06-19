#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> alphabet(26);
    vector<pair<string, string>> words(n);

    for(int i = 0; i < n; i++)
    {
        cin >> words[i].first >> words[i].second;
    }

    for(int i = 0; i < n; i++)
    {
        int word1[26] = { };
        int word2[26] = { };

        for(size_t j = 0; j < words[i].first.length(); j++)
        {
            word1[words[i].first[j] - 97]++;
        }

        for(size_t j = 0; j < words[i].second.length(); j++)
        {
            word2[words[i].second[j] - 97]++;
        }

        for(int j = 0; j < 26; j++)
        {
            alphabet[j] += max(word1[j], word2[j]);
        }
    }

    for(int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << endl;
    }

    return 0;
}