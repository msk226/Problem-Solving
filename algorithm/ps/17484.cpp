#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
int arr[7][7][3]; // 좌 0 하 1 우 2

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j][0];
            arr[i][j][1] = arr[i][j][2] = arr[i][j][0];
            if (j == 0) arr[i][j][0] = 1000;
            if (j == m - 1) arr[i][j][2] = 1000;
        }

    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != 0) {
                arr[i][j][0] += min(arr[i - 1][j - 1][1], arr[i - 1][j - 1][2]);
            }
            arr[i][j][1] += min(arr[i - 1][j][0], arr[i - 1][j][2]);
            if (j != m - 1) {
                arr[i][j][2] += min(arr[i - 1][j + 1][0], arr[i - 1][j + 1][1]);
            }
        }
    }

    int ans = 1000;
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < 3; k++) {
            ans = min(ans, arr[n - 1][j][k]);
        }
    }

    cout << ans;
    return 0;
}
