#include <iostream>
#include <vector>
#include <string>

using namespace std;

char str[20001];
bool take[20001] = {false};
int n, k;
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    for(int i = 0; i < n; i++) {
        if (str[i] == 'H') {
            for (int j = i - k; j <= i + k; j++) {
                if (j >= 0 && j < n && str[j] == 'P') {
                    str[j] = 'A';
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
