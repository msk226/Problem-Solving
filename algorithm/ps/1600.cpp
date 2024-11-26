#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int dmx[8] = {-2, -2, -1, 1, 2, 2, -1, 1};
int dmy[8] = {-1, 1, -2, 2, -1, 1, 2, -2};

int board[201][201];
int visited[31][201][201];
queue<tuple<int, int, int>> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int kn, w, h; cin >> kn >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
    }
    que.push({0, 0 ,0});
    visited[0][0][0] = true;
    while (!que.empty()) {
        int curN, curX, curY;
        tie(curN, curX, curY) = que.front(); que.pop();
        if (curN < kn) {
            for (int i = 0; i < 8; i++) {
                int nx = curX + dmx[i];
                int ny = curY + dmy[i];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if (board[nx][ny] == 1 || visited[curN + 1][nx][ny]) continue;
                que.push({curN + 1, nx, ny});
                visited[curN + 1][nx][ny] = visited[curN][curX][curY] + 1;
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (board[nx][ny] || visited[curN][nx][ny]) continue;
            que.push({curN, nx, ny});
            visited[curN][nx][ny] = visited[curN][curX][curY] + 1;
        }
    }

    int ans = 0x7f7f7f7f;
    for (int i = 0; i < kn + 1; i++)
        if(visited[i][h - 1][w - 1]) ans = min(ans, visited[i][h - 1][w - 1]);
    if (ans != 0x7f7f7f7f) cout << ans - 1;
    else cout << -1;


    return 0;
}