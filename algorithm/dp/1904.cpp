#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

int arr[1000001];
int mod = 15746;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
    }
    cout << arr[n];
    return 0;
}

