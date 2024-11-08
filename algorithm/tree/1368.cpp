#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define X first
#define Y second

vector<pair<int, int>> edge[100005];
bool chk[100005];
int n, e;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cost; cin >> cost;
        edge[0].push_back({cost, i});  // 가상의 노드 0에서 각 노드로의 연결 추가
        edge[i].push_back({cost, 0});  // 역방향 추가
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int cost; cin >> cost;
            if (i >= j) continue;
            edge[i].push_back({cost, j});
            edge[j].push_back({cost, i});  // 양방향 연결 추가
        }
    }

    int cnt = 0;
    int ans = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    chk[0] = 1;

    for (auto cur : edge[0]) {
        pq.push({cur.first, 0, cur.second});
    }

    while (cnt < n) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue;
        ans += cost;
        chk[b] = true;
        cnt++;
        for (auto cur : edge[b]) {
            if (!chk[cur.second])
                pq.push({cur.first, b, cur.second});
        }
    }
    cout << ans;
    return 0;
}