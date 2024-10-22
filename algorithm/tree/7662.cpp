#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int t, k;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> k;
        multiset<int> m;
        while (k--) {
            char c;
            cin >> c;
            if(c == 'D'){
                int q; cin >> q;
                if (m.empty()) continue;
                if (q == 1)
                    m.erase(prev(m.end())); // m.end()는 마지막 요소의 다음 값. prev를 통해 마지막 요소를 가져온다.
                else
                    m.erase(m.begin());
            }else{
                int q; cin >> q;
                m.insert(q);
            }
        }
        if (m.empty())
            cout << "EMPTY\n";
        else
            cout << *prev(m.end()) << ' ' << *m.begin() << '\n';
    }
    return 0;

}



