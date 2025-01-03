#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[101][10001];

bool compare(int i[], int j[]) {
    for (int k = 0; k < n; k++) {
        if (i[k] != j[k]) {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        vector<int> uni;
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            uni.push_back(arr[i][j]);
        }
        sort(uni.begin(), uni.end());
        uni.erase(unique(uni.begin(), uni.end()), uni.end());
        for (int k = 0; k < n; k++) {
            arr[i][k] = lower_bound(uni.begin(), uni.end(), arr[i][k]) - uni.begin();
        }
    }

    int ans = 0;
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            ans += compare(arr[i], arr[j]);
        }
    }
    cout << ans;

    return 0;
}

