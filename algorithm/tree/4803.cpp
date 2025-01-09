#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int n, m, u, v;
vector<int> adj[502];
bool visited[502], isTree;
int trees = 0, tc = 0;

void dfs(int cur, int prev) {
    for (int nxt : adj[cur]) {
        if (nxt == prev) continue;
        if (visited[nxt]) {
            isTree = false;
            continue;
        }
        visited[nxt] = true;
        dfs(nxt, cur);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        fill(visited, visited + n + 1, false);
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        trees = 0;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            isTree = true;
            dfs(i, -1);
            trees += isTree;
        }

        cout << "Case " << ++tc << ": ";
        if (!trees)
            cout << "No trees." << '\n';
        else if (trees == 1)
            cout << "There is one tree." << '\n';
        else
            cout << "A forest of " << trees << " trees." << '\n';
    }
    return 0;
}

