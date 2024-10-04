#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr;
    int x[1000001];
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        arr.push_back(x[i]);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    
    for (int i = 0; i < n; i++) {
        cout << lower_bound(arr.begin(), arr.end(), x[i]) - arr.begin() << '\n';
    }


    return 0;
}

