#include <iostream>
#include <stack>

using namespace std;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        stack<char> stk;
        string str; cin >> str;
        
        // A -> B -> A와 같이 교차되는 substring이 있으면 좋은 문자 X.
        // stk.top() == 현재 검증하는 문자면 pop. 아니면 push.
        for (int j = 0; j < str.length(); j++) {
            if (stk.empty())
                stk.push(str[j]);
            else{
                if (stk.top() == str[j])
                    stk.pop();
                else
                    stk.push(str[j]);
            }
        }
        if (stk.empty())
            count++;
    }
    cout << count << "\n";
    
    return 0;
}

