#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (v[i].first < v[j].first && v[i].second < v[j].second) {
                tmp++;
            }
        }
        cout << tmp + 1 << " ";
    }

    return 0;
}
