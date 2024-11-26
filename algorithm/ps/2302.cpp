#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[41];

vector<int> v = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    v.push_back(n + 1);

    arr[0] = 1; arr[1] = 1; arr[2] = 2;
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    int result = 1;
    for (int i = 1; i < v.size(); i++) result *= arr[v[i] - v[i - 1] - 1];
    cout << result << '\n';

    // 1 2
    // 2 1

    // 1 2 3
    // 2 1 3
    // 1 3 2

    // 1 2 3 4
    // 2 1 3 4
    // 1 3 2 4
    // 1 2 4 3
    // 2 1 4 3

    // 1 2 3 4 5
    // 1 2 4 3 5
    // 2 1 3 4 5
    // 2 1 4 3 5
    // 1 3 2 4 5
    // 1 2 3 5 4
    // 2 1 3 5 4
    // 1 3 2 5 4

    return 0;
}