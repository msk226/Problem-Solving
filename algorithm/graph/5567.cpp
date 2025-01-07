#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, m;
vector<int> friends[501];
int isVisited[501];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        friends[x].push_back(y);
        friends[y].push_back(x);
    }

    int ans = 0;
    queue<int> queue;
    queue.push(1);
    isVisited[1] = 1;

    while (!queue.empty()) {
        auto cur = queue.front(); queue.pop();
        if (isVisited[cur] > 2) continue;

        for (auto tmp : friends[cur]) {
            if (isVisited[tmp] > 0) continue;
            isVisited[tmp] = isVisited[cur] + 1;
            queue.push(tmp);
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}

