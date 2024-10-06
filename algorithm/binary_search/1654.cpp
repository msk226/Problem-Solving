#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int k, n;

int lines[10001];

bool solve(long long mid){
    long long cur = 0;
    for (int i = 0; i < k; i++) {
        cur += lines[i] / mid;
    }
    return cur >= n;
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> k >> n;
    
    for (int i = 0; i < k; i++) {
        cin >> lines[i];
    }
    
    long long low = 1; long long high = 0x7fffffff;
    
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        if (solve(mid))low = mid;
        else high = mid - 1;
    }
    
    cout << low;

    return 0;
}



