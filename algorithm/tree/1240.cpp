#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, u, v, f;
vector<pair<int, int>> adj[1005];
bool vis[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> f;
        adj[u].push_back({v, f});
        adj[v].push_back({u, f});
    }

    while (m--) {
        int x, y; cin >> x >> y;

        queue<pair<int, int>> q;
        fill(vis, vis + n + 1, false);
        q.push({x, 0});
        vis[x] = true;

        while (!q.empty()) {
            auto [cur, dist] = q.front(); q.pop();

            if (cur == y) {
                cout << dist << '\n';
                break;
            }

            for (auto [nxt, nxtDist] : adj[cur]) {
                if (vis[nxt]) continue;
                vis[nxt] = true;
                q.push({nxt, dist + nxtDist});
            }
        }
    }
    return 0;
}

