#include <iostream>
#include <stack>

using namespace std;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    stack<pair<int, int>> stk;
    
    // 입력 받는 정수와 현재 stack의 top을 비교.
    // 만약, 입력 받은 숫자가 더 크다면 현재 num보다 더 큰 수가 나올 때 까지 pop.
    // stk.top의 높이가 더 높다면 그 탑의 위치를 출력하고 반복문 탈출.
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        while (!stk.empty()) {
            if (stk.top().second >= num) {
                cout << stk.top().first << " ";
                break;
            }else
                stk.pop();
        }
        if (stk.empty())
            cout << "0 ";
        
        stk.push({i, num});
    }
    
    return 0;
}

