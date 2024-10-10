#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[301][301];
int board2[301][301]; // 녹기 전 상태 저장
bool isChecked[301][301] = {false, };
queue<pair<int, int>> q;

// 해 마다 해수면 상승 하도록 -> 근처 빙하의 갯수 만큼 줄어든다.
bool discount(){
    
    memcpy(board2, board, sizeof(board));
    
//    cout << "----------------------\n";
    bool over = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (board2[nx][ny] == 0 && board[i][j] >= 1) {
                    board[i][j]--;
                    over = true;
                }
            }
//            cout << board[i][j] << ' ';
        }
//        cout << '\n';
    }
    return over;
}

// 몇 개의 빙하로 나누어져 있는지 체크
int check(){
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 0 && !isChecked[i][j]){
                q.push({i, j}); isChecked[i][j] = true;
                count++;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (isChecked[nx][ny] || board[nx][ny] == 0) continue;
                        q.push({nx, ny}); isChecked[nx][ny] = true;
                    }
                }
            }
        }
    }
    return count;
}

void init(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            isChecked[i][j] = false;
        }
    }
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m; // n -> x(상하), m -> y(좌우),
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int result = 0;
    while (true) {
        if (check() >= 2){
            cout << result << '\n';
            return 0;
        }
        else{
            if(discount()){
                result++;
                init();
            }else{
                cout << "0\n";
                return 0;
            }
            
        }
    }
    return 0;
}



