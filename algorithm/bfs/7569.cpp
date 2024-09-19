#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[101][101][101];
    queue<pair<pair<int, int>, int>> que;
    int m, n, h;
    cin >> m >> n >> h;
    
    // input - ok
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> arr[i][j][k]; // i = z = h -> j = y = n -> k = x = m
                if (arr[i][j][k] == 1) {
                    que.push({{i, j}, k});
                }
            }
        }
    }
    // logic
    while(!que.empty()){
        auto cur = que.front();
        que.pop();
        for(int i = 0; i < 6; i++){ // 0 1 3
            int nz = cur.first.first + dz[i];
            int ny = cur.first.second + dy[i];
            int nx = cur.second + dx[i];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) continue;
            if (arr[nz][ny][nx] == 0){
                arr[nz][ny][nx] = arr[cur.first.first][cur.first.second][cur.second] + 1;
                que.push({{nz, ny}, nx});
            }
        }
    }
    
    
    // output
    int result = 0;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if(arr[i][j][k] == 0){
                    cout << "-1\n";
                    return 0;
                }
                if(result < arr[i][j][k]){
                    result = arr[i][j][k];
                }

            }
        }
    }
    cout << result - 1 << '\n';
    
    return 0;
}

