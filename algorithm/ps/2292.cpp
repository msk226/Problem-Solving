#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n; cin >> n;

    int i = 1;
    int tmp = 1;
    while (true) {
        if (n <= tmp) {
            cout << i;
            break;
        }
        tmp += i * 6;
        i++;
    }
    return 0;
}
