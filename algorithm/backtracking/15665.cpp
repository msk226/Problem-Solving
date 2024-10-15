#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n, m;
int num[10];
int result[10];
bool isused[10];
set<vector<int>> s;

void func(int k){
    if (k == m) {
        vector<int> tmp;
        for (int i = 0 ; i < k; i++)
            tmp.push_back(result[i]);
        s.insert(tmp);
        tmp.clear();
    }else{
        for (int i = 0; i < n; i++) {
        
            result[k] = num[i];
            func(k + 1);
        }
    }
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    
    sort(num, num + n);
    func(0);
    
    for (auto cur : s) {
        for (auto nums: cur) {
            cout << nums << ' ';
        }
        cout << '\n';
    }
    return 0;
}



