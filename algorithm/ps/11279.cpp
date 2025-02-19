#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    priority_queue<int> que;
    for (int i = 0; i < n; i++) {
        int cmd; cin >> cmd;
        if (cmd == 0) {
            if (que.empty()) {
                cout << "0\n";
                continue;
            }
            cout << que.top() << '\n';
            que.pop();
        }
        else {
            que.push(cmd);
        }
    }
    return 0;
}