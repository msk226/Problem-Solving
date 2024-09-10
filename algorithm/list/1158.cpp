#include <iostream>
#include <list>

using namespace std;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    list<int> circle;
    
    for (int i = 1; i <= n; i++)
        circle.push_back(i);

    auto t = circle.begin();

    cout << "<";
    
    while (!circle.empty()) {
        for (int j = 0; j < k - 1; j++){
            t++;
            if (t == circle.end())
                t = circle.begin();
        }
        cout << *t;
        t = circle.erase(t);
        if (!circle.empty()) {
            cout << ", ";
            if (t == circle.end())
                t = circle.begin();
        }
    }
    cout << ">";
    
    return 0;
}

