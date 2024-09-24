#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, arr[64][64];

// 한 범위가 같은 숫자로만 이루어진 경우, true
bool check(int x, int y, int k){
    int pivot = arr[x][y];
    
    for (int i = x; i < x + k; i++) {
        for(int j = y; j < y + k; j++){
            if (pivot != arr[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// 4등분하기
void divide(int x, int y, int k){
    if (check(x, y, k)) {
        cout << arr[x][y];
    }else{
        int index = k / 2;
        cout << "(";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                divide(i * index + x, j * index + y, index);
            }
        }
        cout << ")";
    }
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        string line; cin >> line;
        for (int j = 0; j < line.length(); j++) {
            arr[i][j] = line[j] - '0';
        }
    }
    divide(0, 0, n);

    return 0;
}

