#include <iostream>

using namespace std;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    string t1, t2;
    
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int arr[26] = {0};
        bool check = true;
        
        cin >> t1 >> t2;
        
        for (int j = 0; j < t1.length(); j++)
            arr[t1[j] - 'a'] += 1;
        
        for (int k = 0; k < t2.length(); k++)
            arr[t2[k] - 'a'] -= 1;
        
        for (int m = 0; m < 26; m++) {
            if (arr[m] != 0)
                check = false;
        }
        if (!check)
            cout << "Impossible\n";
        else
            cout << "Possible\n";
        
    }
    return 0;
}

