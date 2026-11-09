#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

const ll MOD = 1e9+7;

vpll moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

char match_direction_to_char(pll node, pll nxt_node)
{
    char ans;
    rep(i, 0, 4)
    {
        ll x = moves[i].ff, y = moves[i].ss;
        if(node.ff+x == nxt_node.ff && node.ss+y == nxt_node.ss)
        {
            if(i==0)
                ans = 'D';
            else if(i==1)
                ans = 'R';
            else if(i==2)
                ans = 'U';
            else ans = 'L';
        }
    }
    return ans;
}

pll match_char_to_direction(char c)
{
    pll ans;
    if(c=='D')
        ans = moves[0];
    else if(c=='R')
        ans = moves[1];
    else if(c=='U')
        ans = moves[2];
    else ans = moves[3];
    return ans;
}

void solve()
{
    ll n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto& x : grid) cin >> x;

    vvll dist(n, vll(m, INT_MAX));
    vector<vector<char>> parent(n, vector<char>(m, '*'));

    auto bfs = [&](pll src)
    {
        queue<pll> q; q.push(src);
        while(!q.empty())
        {
            pll node = q.front(); q.pop();
            if(grid[node.ff][node.ss] == 'B')
            {
                cout << "YES\n";
                cout << dist[node.ff][node.ss] << '\n';

                stack<char> st;
                pll nxt_node = node;

                while(grid[nxt_node.ff][nxt_node.ss] != 'A')
                {
                    char c = parent[nxt_node.ff][nxt_node.ss];
                    st.push(c);
                    pll move = match_char_to_direction(c);
                    nxt_node.ff -= move.ff, nxt_node.ss -= move.ss;
                }

                while(!st.empty())
                {
                    cout << st.top(); 
                    st.pop();
                }

                cout << '\n';
                return true;
            }

            for(auto [x, y] : moves)
            {
                pll nxt_node = {node.ff+x, node.ss+y};
                if(nxt_node.ff >= 0 && nxt_node.ff < n && nxt_node.ss >= 0 && nxt_node.ss < m
                && grid[nxt_node.ff][nxt_node.ss] != '#' && dist[nxt_node.ff][nxt_node.ss] == INT_MAX)
                {
                    q.push(nxt_node);
                    parent[nxt_node.ff][nxt_node.ss] = match_direction_to_char(node, nxt_node);
                    dist[nxt_node.ff][nxt_node.ss] = dist[node.ff][node.ss] + 1;
                }
            }
        }

        return false;
    };

    rep(i, 0, n)
        rep(j, 0, m)
            if(grid[i][j]=='A')
            {
                dist[i][j] = 0;
                if(!bfs({i, j}))   
                    cout << "NO\n";
            }
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
