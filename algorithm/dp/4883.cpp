#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int cnt = 0;

int board[100001][3];
int result[100001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> n;
        if (n == 0) break;

        cnt++;
        for (int i = 0; i < n; i++) {
            cin >> result[i][0] >> result[i][1] >> result[i][2];
        }

        board[0][0] = 111111;
        board[0][1] = result[0][1];
        board[0][2] = result[0][1] + result[0][2];

        for (int i = 1; i < n; i++) {
            board[i][0] = min(board[i - 1][0], board[i - 1][1]) + result[i][0];
            board[i][1] = min({board[i - 1][0], board[i - 1][1], board[i - 1][2], board[i][0]}) + result[i][1];
            board[i][2] = min({board[i - 1][1], board[i - 1][2], board[i][1]}) + result[i][2];
        }
        cout << cnt << ". " << board[n - 1][1] << '\n';

    }
    return 0;
}

