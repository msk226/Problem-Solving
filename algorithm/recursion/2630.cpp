#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a = 0, b = 0;
int n, arr[130][130];


// 유효한 색종이가 있는지 확인
bool check(int x, int y, int limit){
    int pivot = arr[x][y];
    
    for (int i = x; i < x + limit; i++) {
        for (int j = y; j < y + limit; j++) {
            if (pivot != arr[i][j]) {
                return false;
            }
        }
    }
    return true;
}


// arr 분해
void divide(int x, int y, int limit){
    
    if (check(x, y, limit)) {
        if (arr[x][y] == 0) a++;
        else if (arr[x][y] == 1) b++;
    }
    else{
        int index = limit / 2;
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                divide(index * i + x, index * j + y, index);
            }
        }
    }
}


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    divide(0, 0, n);
    
    cout << a << '\n' << b << '\n';

    return 0;
}

