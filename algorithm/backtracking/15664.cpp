#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n,m;
int arr[10];
set<vector<int>> s;
int result[10];
bool isused[10];




void func(int k){
    if (k == m) {
        vector<int> tmp;
        for(int i = 0; i < m; i++)
            tmp.push_back(result[i]);
        s.insert(tmp);
        tmp.clear();
    }else{
        for (int i = 0; i < n; i++) {
            if (!isused[i] && result[k - 1] <= arr[i] ) {
                isused[i] = true;
                result[k] = arr[i];
                func(k + 1);
                isused[i] = false;
            }
        }
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
    
    for(auto vector : s){
        for(auto num : vector){
            cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
}



