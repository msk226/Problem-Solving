#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool visited[100001];
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> que;

    que.push({0, n});
    visited[n] = true;

    while (!que.empty()) {
        auto cur = que.top(); que.pop();

        if (cur.second == k) {
            cout << cur.first << '\n';
            break;
        }

        if (cur.second * 2 < 100001 && !visited[cur.second * 2]) {
            que.push({cur.first, cur.second * 2});
            visited[cur.second * 2] = true;
        }
        if (cur.second - 1 >= 0 && !visited[cur.second - 1]) {
            que.push({cur.first + 1, cur.second - 1});
            visited[cur.second - 1] = true;
        }
        if (cur.second + 1 < 100001 && !visited[cur.second + 1]) {
            que.push({cur.first + 1, cur.second + 1});
            visited[cur.second + 1] = true;
        }
    }
    return 0;
}
