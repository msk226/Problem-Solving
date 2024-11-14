#include <iostream>

using namespace std;

int h, w, n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w >> n >> m;
    int row_min = w  / (m + 1);
    if (w % (m + 1) != 0) {
        row_min++;
    }
    int col_min = h / (n + 1);
    if (h % (n + 1) != 0) {
        col_min++;
    }

    cout << row_min * col_min;
    return 0;
}
