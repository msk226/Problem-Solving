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
    while (true) {
        char arr[31][31][31];
        int visit[31][31][31] = {-1, };

        queue<pair<pair<int, int>, pair<int, int>>> que;
        
        int m, n, h, ans = 0;
        bool end = false;
        cin >> m >> n >> h;
        
        // end condition
        if (m == 0 && n == 0 && h == 0) {
            break;
        }

        // input - ok
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < h; k++) {
                    cin >> arr[i][j][k]; // i = z = m -> j = y = n -> k = x = h
                    if (arr[i][j][k] == 'S') {
                        que.push({{i, j}, {k, 0}});
                    }
                }
            }
        }
        
        // logic
        while(!que.empty()){
            auto cur = que.front();
            que.pop();
            for(int i = 0; i < 6; i++){
                int nz = cur.first.first + dz[i];
                int ny = cur.first.second + dy[i];
                int nx = cur.second.first + dx[i];
                int cnt = cur.second.second;
                
                if(nx < 0 || ny < 0 || nz < 0 || nx >= h || ny >= n || nz >= m) continue;
                
                if(arr[nz][ny][nx] == 'E'){
                    end = true; 
                    ans = cnt + 1;
                    break;
                }
                
                if(arr[nz][ny][nx] == '.' && visit[nz][ny][nx] == 0){
                    visit[nz][ny][nx] = 1;
                    que.push({{nz, ny}, {nx, cnt + 1}});
                }
            }
        }
        
        // output
        if (end)
            cout << "Escaped in " << ans << " minute(s).\n";
        else
            cout << "Trapped!\n";
        
        
        
    }
    return 0;
}

