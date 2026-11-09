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
    vector<vector<char>> parent(n, vector<char>(m));
    stack<char> st;

    queue<pair<pll, bool>> npcs;
    pll src;
    bool flag = true;


    auto bfs = [&](pll src)
    {
        queue<pll> q; q.push(src);

        while(!q.empty())
        {
            pll node = q.front(); q.pop();

            if(node.ff == 0 || node.ff == n-1 || node.ss == 0 || node.ss == m-1)
            {
                while(node != src)
                {
                    char c = parent[node.ff][node.ss];
                    pll move = match_char_to_direction(c);
                    node = {node.ff-move.ff, node.ss-move.ss};
                    st.push(c);
                }
                return;
            }

            for(auto [x, y] : moves)
            {
                pll nxt_node = {node.ff+x, node.ss+y};
                if(nxt_node.ff >= 0 && nxt_node.ff < n && nxt_node.ss >= 0 && nxt_node.ss < m
                && grid[nxt_node.ff][nxt_node.ss] == 'A' && dist[nxt_node.ff][nxt_node.ss] == INT_MAX)
                {
                    q.push(nxt_node);
                    dist[nxt_node.ff][nxt_node.ss] = dist[node.ff][node.ss] + 1;
                    parent[nxt_node.ff][nxt_node.ss] = match_direction_to_char(node, nxt_node);
                }
            }
        }
    };

    auto spread = [&](pll node, bool is_monster)
    {
        for(auto [x, y] : moves)
        {
            pll nxt_node = {node.ff+x, node.ss+y};
            if(nxt_node.ff >= 0 && nxt_node.ff < n && nxt_node.ss >= 0 && nxt_node.ss < m && grid[nxt_node.ff][nxt_node.ss] == '.')
            {
                grid[nxt_node.ff][nxt_node.ss] = (is_monster ? 'M' : 'A');
                if((nxt_node.ff == 0 || nxt_node.ff == n-1 || nxt_node.ss == 0 || nxt_node.ss == m-1) && !is_monster)
                {
                    bfs(src);
                    cout << "YES\n";
                    flag = false;
                    cout << dist[nxt_node.ff][nxt_node.ss] << '\n';
                    while(!st.empty())
                    {
                        cout << st.top();
                        st.pop();
                    }
                    cout << '\n';
                    return;
                }
                npcs.push({nxt_node, is_monster});
            }
        }

    };

    rep(i, 0, n)
        rep(j, 0, m)
        {
            if(grid[i][j]=='M')
                npcs.push({{i, j}, true});
            else if(grid[i][j]=='A')
            {
                src = {i, j};
                dist[i][j] = 0;
            }
        }
    
    npcs.push({{src.ff, src.ss}, false});

    if(src.ff == 0 || src.ss == 0 || src.ff == n-1 || src.ss == m-1)
    {
        cout << "YES\n0\n";
        return;
    }


    while(!npcs.empty() && flag)
    {
        spread(npcs.front().ff, npcs.front().ss);
        npcs.pop();
    }

    if(flag)
        cout << "NO\n";

}

signed main()
{
    //fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
