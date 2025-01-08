#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n, m;
int board[102][102];
bool isVisited[102];

bool dfs(int st, int tar) {
    fill(isVisited, isVisited + n + 2, false);
    stack<int> stk;
    stk.push(st);

    while (!stk.empty()) {
        int cur = stk.top(); stk.pop();
        if (isVisited[cur]) continue;
        if (cur != st) isVisited[cur] = true;

        for (int nxt = 0; nxt < n; nxt++) {
            if (isVisited[nxt]) continue;
            if (board[cur][nxt] == 1) {
                if (nxt == tar) return true;
                stk.push(nxt);
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dfs(i, j) << ' ';
        }
        cout << '\n';
    }

    return 0;
}

