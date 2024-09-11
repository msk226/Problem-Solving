#include <iostream>
#include <stack>

using namespace std;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> stk;
    string result;
    int answer[100001];
    int idx = 0, num = 1;
    int n; cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> answer[i];
    
    stk.push(1); // 초기값 세팅
    
    // 주어진 범위 내에서만 반복
    while (idx < n) {
        
        // 만드려는 수열의 현재 값이 num 보다 크거나 같다면, stk에 push
        if (answer[idx] >= num) {
            stk.push(num);
            num++;
            result += "+\n";
        }
        // 만약 stk의 top 값이 수열의 현재 값과 일치하면 pop
        if (answer[idx] == stk.top()){
            stk.pop();
            idx++;
            result += "-\n";
        }else if(answer[idx] < stk.top()){ // stk의 top 값이 수열의 현재 값보다 크다는 것은 더 이상 가능한 경우의 수가 없다는 의미.
            result = "NO\n";
            break;
        }
    }
    cout << result;
    return 0;
}

