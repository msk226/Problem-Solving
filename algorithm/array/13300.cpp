#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int count[2][7] = {0, };
    
    int n, k, s, y;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s >> y;
        count[s][y - 1]++;
    }
    
    int total = 0;
    
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 6; j++) {
            total += (count[i][j] + k - 1) / k;
        }
    }
    cout << total << "\n";
    
    return 0;
}

