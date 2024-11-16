#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> v[10001];

int n, d;
int st, en, w;
int idx, pnt = 0;
int arr[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;

    for (int i = 1; i <= d; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> st >> en >> w;
        if (en > d || en - st <= w) continue;
        v[st].push_back({en, w});
    }

    for (int i = 0; i <= d; i++) {
        if (i == 0) arr[i] = 0;
        else arr[i] = min(arr[i], arr[i - 1] + 1);

        if (v[i].empty()) continue;

        for (auto cur : v[i]) {
            arr[cur.first] = min(arr[cur.first], arr[i] + cur.second);
        }
    }

    cout << arr[d];
    return 0;
}
