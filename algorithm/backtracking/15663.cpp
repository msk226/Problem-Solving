#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
int isUsed[10];
int result[10];

void func(int k){
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }cout << '\n';
        
    }else{
        int past = 0;
        for (int i = 0; i < arr.size(); i++) {
            // 최근 수열의 제일 마지막 값이 현재 바라보는 값과 같으면 중복임.
            if (!isUsed[i] && past != arr[i]) {
                result[k] = arr[i];
                past = result[k];
                isUsed[i] = true;
                func(k + 1);
                isUsed[i] = false;
            }
        }
    }
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    
    // 정렬
    sort(arr.begin(), arr.end());
    
    
    // 1 7 9 9
    func(0);
    // 17 19 71 79 91 97 99
    
    

    return 0;
}



