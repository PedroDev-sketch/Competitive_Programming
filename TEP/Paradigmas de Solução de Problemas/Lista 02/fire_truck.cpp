#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

int numfire, total, oindex = 0;

void prune_dfs(int source, vector<vector<int>> &adjlist, vector<bool> &visited)
{
    stack<int> line;
    line.push(source);

    while (!line.empty())
    {
        int save = line.top();
        line.pop();
        visited[save - 1] = false;

        for (auto p : adjlist[save])
        {
            if (visited[p - 1])
                line.push(p);
        }
    }
}

void dfs(int source, vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> layover)
{
    if(source == numfire)
    {
        layover.push_back(source);
        for(int i = 0; i < layover.size(); i++)
        {
            cout << layover[i] << (i+1 == layover.size() ? "" : " ");
        }
        cout << '\n';

        total++;
    }

    layover.push_back(source);

    for (auto p : adjlist[source])
    {
        //cout << source << ' ' << p << ' ' << visited[p-1] << '\n';
        if (!visited[p - 1])
        {
            visited[p - 1] = true;
            dfs(p, adjlist, visited, layover);
            visited[p - 1] = false;
        }
    }
    visited[source-1] = true;
}

signed main()
{
    while (cin >> numfire)
    {
        total = 0;
        oindex++;

        vector<vector<int>> adjlist(21);

        int a, b, top = -1;
        while (cin >> a >> b, a || b)
        {
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
            top = max(top, a);
            top = max(top, b);
        }

        cout << "CASE " << oindex << ":\n";

        vector<bool> visited(top, true);

        prune_dfs(numfire, adjlist, visited);

        for(auto& p : adjlist)
        {
            sort(all(p));
        }

        vector<int> l;
        visited[0] = true;
        dfs(1, adjlist, visited, l);

        cout << "There are " << total << " routes from the firestation to streetcorner " << numfire << ".\n";
    }

    return 0;
}