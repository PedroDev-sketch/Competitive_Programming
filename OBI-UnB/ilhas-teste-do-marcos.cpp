#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
ll oo = 1e7;

pair<vll, vi> dijkstra(const vector<vector<pll>> &g, int n,
                       int s) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  vll dist(n, oo);
  vi p(n, -1);
  pq.emplace(0, s);
  dist[s] = 0;
  while (!pq.empty()) {
    auto [d1, v] = pq.top();
    pq.pop();
    if (dist[v] < d1) continue;

    for (auto [d2, u] : g[v]) {
      if (dist[u] > d1 + d2) {
        dist[u] = d1 + d2;
        p[u] = v;
        pq.emplace(dist[u], u);
      }
    }
  }
  return {dist, p};
}

int main()
{
    int n, m, u, v, p;
    cin >> n >> m;

    vector<vector<pll>> grafo(n);

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> p;
        
        pll par = {v-1, p};
        grafo[u-1].push_back(par);
        par = {u-1, p};
        grafo[v-1].push_back(par);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            
        }
    }

    int s;
    cin >> s;

    return 0;
}