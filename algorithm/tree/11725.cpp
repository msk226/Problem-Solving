#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<int> arr[100001];
int p[100001];

void dfs(int cur){
    for(int idx : arr[cur]){
        if (p[cur] == idx) continue;
        p[idx] = cur;
        dfs(idx);
    }
}

void bfs(int root){
    queue<int> que;
    que.push(root);
    while (!que.empty()) {
        int cur = que.front(); que.pop();
        for(auto idx : arr[cur]){
            if(p[cur] == idx) continue;
            p[idx] = cur;
            que.push(idx);
        }
    }
}

int main() {
    
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    bfs(1);

    for (int i = 2; i <= n; i++) {
        cout << p[i] << '\n';
    }
    
    
    return 0;
}



