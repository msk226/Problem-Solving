#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define X first
#define Y second

int v, e;
vector<pair<int, int>> adj[10005];
bool chk[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int cnt = 0; // 현재 선택된 간선의 수
    int ans = 0;

    // tuple<int,int,int> : {비용, 정점 1, 정점 2}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    chk[1] = 1;

    // 1번 정점
    for (auto cur : adj[1]) {
        pq.push({cur.X, 1, cur.Y });
    }

    while (cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue;
        ans += cost;
        chk[b] = true;
        cnt++;

        for (auto cur : adj[b]) {
            if (!chk[cur.Y])
                pq.push({cur.X, b, cur.Y});
        }
    }
    cout << ans;
    return 0;
}
