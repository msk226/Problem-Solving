#include <iostream>
#include <vector>

using namespace std;

int n, m;
int maxNum = 0x3f3f3f3f;
int arr[101][101];
int nxt[101][101];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = maxNum;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
        nxt[a][b] = b;
    }

    for (int i = 1; i <= n; i++) {
        arr[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (arr[j][k] > arr[j][i] + arr[i][k]) {
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
                    nxt[j][k] = nxt[j][i];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == maxNum) {
                cout << "0 ";
            }
            else {
                cout << arr[i][j] << " ";
            }
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 0 || arr[i][j] == maxNum) {
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int start = i;
            while (start != j) {
                path.push_back(start);
                start = nxt[start][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for(auto x : path) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}
