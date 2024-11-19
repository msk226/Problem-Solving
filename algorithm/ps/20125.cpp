#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char cookie[1001][1001];
bool visited[1001][1001];
int n, heart_x, heart_y;

bool check(int x, int y) {
    for (int j = 0; j < 4; j++) {
        int cx = x + dx[j];
        int cy = y + dy[j];
        if (cookie[cx][cy] != '*') return false;
    }
    return true;
}

int count_left(int x, int y) {
    int cnt = 0;
    y--;
    while (cookie[x][y] == '*' && y > 0) {
        cnt++;
        y--;
    }
    return cnt;
}

int count_right(int x, int y) {
    int cnt = 0;
    while (y <= n) {
        y++;
        if (cookie[x][y] == '*') cnt++;
        else break;
    }
    return cnt;
}

pair<pair<int, int>, int> count_down(int x, int y) {
    int cnt = 0;
    while (x <= n) {
        x++;
        if (cookie[x][y] == '*') cnt++;
        else break;
    }

    int left_leg_cnt = 0; int left_x = x; int left_y = y - 1;
    while (left_x <= n) {
        if (cookie[left_x][left_y] == '*') left_leg_cnt++;
        else break;
        left_x++;
    }

    int right_leg_cnt = 0; int right_x = x; int right_y = y + 1;
    while (right_x <= n) {
        if (cookie[right_x][right_y] == '*') right_leg_cnt++;
        else break;
        right_x++;
    }

    return {{cnt, left_leg_cnt}, right_leg_cnt};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cookie[i][j];
        }
    }
    queue<pair<int, int>> que;
    que.push({1, 1});
    visited[1][1] = true;

    while (!que.empty()) {
        auto cur = que.front(); que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx > n || ny > n || nx <= 0 || ny <= 0) continue;
            if (visited[nx][ny]) continue;
            if (check(nx, ny)) {
                heart_x = nx;
                heart_y = ny;
                break;
            }
            que.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    cout <<  heart_x << ' ' << heart_y << '\n';
    auto tmp = count_down(heart_x, heart_y);
    cout << count_left(heart_x, heart_y) << ' ' << count_right(heart_x, heart_y) << ' ' << tmp.first.first  << ' ' << tmp.first.second << ' ' << tmp.second;

    return 0;
}
