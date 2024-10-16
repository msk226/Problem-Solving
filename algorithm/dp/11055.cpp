#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
int result[1001];


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    result[0] = arr[0];
    for (int i = 1; i < n; i++) {
        for (int j = i - 1 ; j >= 0; j--) {
            if (arr[i] <= arr[j]){
                result[i] = max(arr[i], result[i]);
                continue;
            }
            result[i] = max(result[i], result[j] + arr[i]);
        }
    }
    cout << *max_element(result, result + n);
    

    return 0;
}



