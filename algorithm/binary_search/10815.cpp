#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int my[500001];
int given[500001];

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> my[i];
    }
    
    sort(my, my + n);
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> given[i];
        cout << binary_search(my, my + n, given[i]) << ' ';
    }
    

    return 0;
}



