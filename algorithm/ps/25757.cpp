#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;
int n;
char y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> y;

    int player = 0;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        if (m.find(name) == m.end()) {
            player++;
            m.insert({name, i});
        }
    }

    if (y == 'Y')
        cout << player / 1 << '\n';
    else if (y == 'F')
        cout << player / 2 << '\n';
    else
        cout << player / 3 << '\n';
    return 0;
}
