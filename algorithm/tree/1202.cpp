#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

pair<int, int> jewelry[300001];
multiset<int> bag;

int n, m;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> jewelry[i].second >> jewelry[i].first;
    }
    
    sort(jewelry, jewelry + n);
    
    for (int i = 0; i < m; i++) {
        
        int ipt;
        cin >> ipt;
        bag.insert(ipt);
    }
    
    long long result = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        int m = jewelry[i].second;
        int v = jewelry[i].first;
        
        auto it = bag.lower_bound(m);
        
        if (it == bag.end()) continue;
        
        result += v;
        bag.erase(it);
    }
    cout << result << '\n';
    return 0;
}



