#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 벽을 부순 경우의 최단 거리와 안부순 경우의 최단 거리를 따로 관리 해야함...
int n, m;
queue<pair<pair<int, int>, bool>> q;
bool visited[1001][1001][2]; // 0: 벽을 부수지 않음, 1: 벽을 부숨
int board[1001][1001];
int result[1001][1001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string input;
        cin >> input;
        for (int j = 1; j <= m; j++) {
            board[i][j] = input[j - 1] - '0';
        }
    }

    // 초기값 설정
    visited[1][1][0] = true;
    q.push({{1, 1}, false});
    result[1][1][0] = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int curX = cur.first.first;
        int curY = cur.first.second;
        bool broken = cur.second; // 현재까지 벽을 부쉈는지 여부

        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            // 범위 체크
            if (nx > n || ny > m || nx <= 0 || ny <= 0) continue;

            // 벽을 부수지 않고 이동할 경우
            if (board[nx][ny] == 0 && !visited[nx][ny][broken]) {
                visited[nx][ny][broken] = true;
                result[nx][ny][broken] = result[curX][curY][broken] + 1;
                q.push({{nx, ny}, broken});
            }
            // 벽을 만나고, 아직 벽을 부순 적이 없는 경우에 벽을 부수고 이동
            else if (board[nx][ny] == 1 && !broken && !visited[nx][ny][1]) {
                visited[nx][ny][1] = true;
                result[nx][ny][1] = result[curX][curY][0] + 1;
                q.push({{nx, ny}, true});
            }
        }
    }

    // 최종 결과
    int no_break = result[n][m][0];
    int with_break = result[n][m][1];
    int answer;
    if (no_break != 0 && with_break != 0) { // 두 경로가 모두 존재할 때
        answer = min(no_break, with_break); // 더 짧은 경로 선택
    } else { // 하나의 경로만 존재할 때
        answer = max(no_break, with_break); // 존재하는 경로를 선택
    }


    if (answer == 0) answer = -1;
    cout << answer << '\n';

    return 0;
}
