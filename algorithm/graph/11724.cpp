#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

vector<int> arr[1001];
bool isvisted[1001];

int main() {
    
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (isvisted[i]) continue;
        num++;
        queue<int> que;
        que.push(i);
        isvisted[i] = true;
        while (!que.empty()) {
            auto cut = que.front(); que.pop();
            for (auto nxt : arr[cut]) {
                if (isvisted[nxt]) continue;
                que.push(nxt);
                isvisted[nxt] = true;
            }
        }
    }
    
    cout << num << '\n';
    return 0;
}



