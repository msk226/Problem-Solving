#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> sum;
    int arr[1001];
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum.push_back(arr[i] + arr[j]);
        }
    }
    
    sort(sum.begin(), sum.end());
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (binary_search(sum.begin(), sum.end(), arr[i] - arr[j])) {
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
}

