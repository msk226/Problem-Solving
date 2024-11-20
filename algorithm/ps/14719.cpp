#include <iostream>
#include <string>

using namespace std;

int h, w;
int n;
int block[501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    for (int i = 0; i < w; i++) {
        cin >> block[i];
    }

    int result = 0;

    for (int i = 1; i < w - 1; i++) {
        int left = 0; int right = 0;

        for (int j = i - 1; j >= 0; j--) {
            left = max(left, block[j]);
        }
        for (int j = i + 1; j < w; j++) {
            right = max(right, block[j]);
        }
        result += max(0, min(left, right) - block[i]);
    }
    cout << result << '\n';
    return 0;
}
