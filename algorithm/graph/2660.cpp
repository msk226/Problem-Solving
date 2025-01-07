#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<int> friends[51];
int result[51];

int search(int num) {
    queue<int> q;
    int dist[51];
    fill(dist, dist + n + 1, -1);
    q.push(num); dist[num] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : friends[cur]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    int mx = *max_element(dist + 1, dist + n + 1);
    if (mx == 0) return 1000;
    return mx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    while (true) {
        int x, y; cin >> x >> y;
        if (x == -1 && y == -1) break;
        friends[x].push_back(y);
        friends[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        result[i] = search(i);
    }

    vector<int> winners;
    int mn = *min_element(result + 1, result + n + 1);
    for (int i = 1; i <= n; i++) {
        if (mn == result[i]) {
            winners.push_back(i);
        }
    }

    cout << mn << ' ' << winners.size() << '\n';
    for (auto cur : winners) {
        cout << cur << ' ';
    }

    return 0;
}

