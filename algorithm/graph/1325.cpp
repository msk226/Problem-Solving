#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int n, m;
int mx;
vector<int> adj[10001];
bool visited[10001];
int sc[10001];

void bfs(int num) {
    visited[num] = true;
    sc[num]++;
    mx = max(mx, sc[num]);
    for (auto nxt : adj[num]) {
        if (visited[nxt]) continue;
        bfs(nxt);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i++) {
        fill(visited, visited + n + 1, false);
        bfs(i);
    }

    for(int i = 1; i <= n; i++)
        if(sc[i] == mx) cout << i << ' ';

    return 0;
}

