#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100005];
int mn = 0x7fffffff;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int en = 0;
    int sum = arr[0];
    for (int st = 0; st < n; st++) {
        while(en < n && sum < m) {
            en++;
            sum += arr[en];
        }
        if (en == n) break;
        mn = min(mn, en - st + 1);
        sum -= arr[st];
    }
    if (mn == 0x7fffffff)
        cout << "0\n";
    else
        cout << mn;

    return 0;
}



