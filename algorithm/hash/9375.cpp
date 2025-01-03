#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int n, m;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m;
        unordered_map<string, int> mp;
        for (int j = 0; j < m; j++) {
            string name, type;
            cin >> name >> type;
            mp[type]++;
        }

        int ans = 1;
        for (auto tmp : mp) {
            ans *= tmp.second + 1;
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}

