#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr1[100001];
int arr2[100001];

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    
    cin >> m;
    
    sort(arr1, arr1 + n);
    
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
        cout << binary_search(arr1, arr1 + n, arr2[i]) << '\n';
    }
    
    return 0;
}



