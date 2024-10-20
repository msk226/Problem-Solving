#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<string> s;
int n;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    string name, state;
    for (int i = 0; i < n; i++) {
        cin >> name >> state;
        if (state == "enter") {
            s.insert(name);
        }else{
            s.erase(name);
        }
    }
    
    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end(), greater<string>());
    for(auto cur : v)
        cout << cur << '\n';
    
    return 0;

}



