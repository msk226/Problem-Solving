#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x;
vector<pair<int, int>> adj[1001];
int d[1001];
const int INF = 1e9 + 10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;

    while (m--) {
        int st, en, w;
        cin >> st >> en >> w;
        adj[st].push_back({w, en});
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        fill(d, d + n + 1, INF);
        int cnt = 0;
        if (i == x) continue;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        que.push({0, i});
        d[i] = 0;

        while (!que.empty()) {
            auto cur = que.top(); que.pop();
            if (d[cur.second] != cur.first) continue;
            for (auto nxt : adj[cur.second]) {
                if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
                d[nxt.second] = d[cur.second] + nxt.first;
                que.push({d[nxt.second], nxt.second});
            }
        }
        cnt += d[x];


        fill(d, d + n + 1, INF);
        que.push({0, x});
        d[x] = 0;

        while (!que.empty()) {
            auto cur = que.top(); que.pop();
            if (d[cur.second] != cur.first) continue;
            for (auto nxt : adj[cur.second]) {
                if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
                d[nxt.second] = d[cur.second] + nxt.first;
                que.push({d[nxt.second], nxt.second});
            }
        }
        cnt += d[i];

        if (mx <= cnt) mx = cnt;
    }

    cout << mx << '\n';
    return 0;
}
