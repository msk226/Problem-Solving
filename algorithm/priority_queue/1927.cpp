#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;

int main() {
    
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> q;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            if (!q.empty()) {
                cout << q.top() << '\n';
                q.pop();
            }else{
                cout << "0\n";
            }
            continue;
        }
        q.push(tmp);
        
    }

    return 0;
}



