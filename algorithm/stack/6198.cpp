#include <iostream>
#include <stack>

using namespace std;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    long long count = 0;
    stack<pair<int, int>> stk;

    for (int i = 1; i <= n; i++) {
        int num; cin >> num; // 6
        while (!stk.empty()) {
            if (stk.top().second > num) { // 12 >= 6
                count += stk.size();
                break;
            }else
                stk.pop();
        }
        
        stk.push({i, num}); // 12
    }
    cout << count << '\n';
    
    return 0;
}

