#include <iostream>
#include <string>

using namespace std;

int n, num, tmp, sm;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int arr[21]; int result = 0;
        cin >> num;
        for (int j = 0; j < 20; j++) cin >> arr[j];
        for (int a = 0; a < 20; a++) {
            for (int b = a; b < 20; b++) {
                if(arr[a] > arr[b]) {
                    result += 1;
                }
            }
        }
        cout << num << ' ' << result << '\n';
    }



    return 0;
}
