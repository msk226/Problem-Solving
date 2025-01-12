#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[1002];
vector<int> result;
int dgr[1002];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int num, u, v;
    for (int i = 0; i < m; i++) {
        cin >> num;
        cin >> u;
        while (--num) {
            cin >> v;
            adj[u].push_back(v);
            dgr[v]++;
            swap(u, v);
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (dgr[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for (int nxt : adj[cur]) {
            dgr[nxt]--;
            if (dgr[nxt] == 0) q.push(nxt);
        }
    }

    if (result.size() != n) cout << "0\n";
    else for (auto s : result) cout << s << ' ';


    return 0;
}

