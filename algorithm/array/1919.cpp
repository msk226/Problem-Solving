#include <iostream>

using namespace std;


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    string t1, t2;
    int arr[26] = {0};
    int count = 0;

    cin >> t1 >> t2;
    
    for (int i = 0; i < t1.length(); i++)
        arr[t1[i] - 'a'] += 1;
    
    for (int j = 0; j < t2.length(); j++)
        arr[t2[j] - 'a'] -= 1;
    
    for (int k = 0; k < 26; k++) {
        if (arr[k] > 0)
            count += arr[k];
        else if(arr[k] < 0)
            count -= arr[k];
    }
    
    cout << count << "\n";
    
    return 0;
}

