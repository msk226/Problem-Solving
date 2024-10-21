#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> s;
string i2s[100001];
int n, m;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    string name;
    for (int i = 1; i <= n; i++) {
        cin >> i2s[i];
        s[i2s[i]] = i;
    }
    string tmp;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        if(isdigit(tmp[0]))
            cout << i2s[stoi(tmp)] << '\n';
        else
            cout << s[tmp] << '\n';
    }
    return 0;

}



