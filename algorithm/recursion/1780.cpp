#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a = 0, b = 0, c = 0;
int n, arr[2200][2200];

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
        if (arr[x][y] == -1) a++;
        else if (arr[x][y] == 0) b++;
        else c++;
    }
    else{
        int index = limit / 3;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
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
    
    cout << a << '\n' << b << '\n' << c << '\n';

    return 0;
}

