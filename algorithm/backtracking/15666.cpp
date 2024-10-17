#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int arr[10];
int result[10];
bool isused[10];
set<vector<int>> s;

void func(int k){
    if (k == m) {
        vector<int> tmp;
        for (int i = 0; i < k; i++) {
            tmp.push_back(result[i]);
        }
        s.insert(tmp);
        tmp.clear();
        return;
    }
    for (int i = 0; i < n; i++) {
        if (k > 0 && result[k - 1] > arr[i]) {
            continue;
        }
        result[k] = arr[i];
        func(k + 1);
    }
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    func(0);
    
    for(auto cur : s){
        for(int num : cur){
            cout << num << ' ';
        }cout << '\n';
    }


    return 0;
}



