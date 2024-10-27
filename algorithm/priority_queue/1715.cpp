#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int n;
int ans = 0;

int main() {
    
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        int tmp; cin >> tmp;
        q.push(tmp);
    }
    
    while (q.size() > 1) {
        int first = q.top(); q.pop();
        int second = q.top(); q.pop();
        
        ans += first + second;
        
        q.push(first + second);
    }
    
    cout << ans << '\n';

    return 0;
}



