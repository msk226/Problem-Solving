#include <iostream>
#include <vector>

using namespace std;

int n, m;
int maxNum = 0x3f3f3f3f;
int arr[101][101];


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

    for (int i = 1; i <= n; i++) {
        arr[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
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

    return 0;
}
