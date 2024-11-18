#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int a = 0; a < t; a++) {
        int n, k, t_id, m;
        long long my_team_point = 0, team_result = 0;
        int team_point[101][101] = {0, };
        int team_info[101][2] = {0, }; // 0 -> 최종 제출 시간, 1 -> 제출 횟수

        cin >> n >> k >> t_id >> m;
        for (int b = 0; b < m; b++) {
            int i, j, s;
            cin >> i >> j >> s;
            if (team_point[i][j] <= s) {
                if (i == t_id) {
                    my_team_point -= team_point[i][j];
                    my_team_point += s;
                }
                team_point[i][j] = s;
            }
            team_info[i][0] = b;
            team_info[i][1]++;
        }
        for (int c = 1; c <= n; c++) {
            if (c == t_id) continue;
            long long pnt = 0;
            for (int d = 0; d <= k; d++) {
                pnt += team_point[c][d];
            }
            if (pnt > my_team_point) {
                team_result++;
            }else if (pnt == my_team_point) {
                if (team_info[t_id][1] < team_info[c][1]) {
                    continue;
                }
                if (team_info[t_id][1] > team_info[c][1]) team_result++;
                else {
                    if (team_info[t_id][0] < team_info[c][0]) continue;
                    team_result++;
                }
            }
        }
        cout << team_result + 1 << '\n';
    }

    return 0;
}
