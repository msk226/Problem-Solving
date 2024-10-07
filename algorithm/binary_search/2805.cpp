#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;
long long arr[1000001];

bool solve(long long mid){
    long long cur = 0;
    for(int i = 0; i < n; i++){
        if (arr[i] - mid >= 0)
            cur += arr[i] - mid;
    }
    return cur >= m;
}


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);
    
    long long low = 0;
    long long high = arr[n - 1];
    
    while(low < high){
        // 자르는 높이
        long long mid = (low + high + 1) / 2;
        
        if (solve(mid)) low = mid;
        
        else high = mid - 1;
    }
    
    cout << low;
    
    return 0;
}



