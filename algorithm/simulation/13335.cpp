#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> bridge;
int trucks[1001];
int n, w, l;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    // n = 트럭의 수, w = 다리의 길이, l = 최대 하중
    cin >> n >> w >> l;
    
    for (int i = 0; i < n; i++)
        cin >> trucks[i];
    
    int weight = 0;
    int time = 0;
    int index = 0;

    for (int i = 0; i < n; i++) {
        while (true) {
            if (bridge.size() == w) {
                weight -= bridge.front();
                bridge.pop();
            }
            if (weight + trucks[i] <= l) break;
            bridge.push(0);
            time++;
        }
        bridge.push(trucks[i]);
        weight += trucks[i];
        time++;
    }
    
    // 마지막 트럭이 다리 위에 올라온 상태. 마지막 트럭이 나갈 때 까지 기다림
    cout << time + w << '\n';
    return 0;
}



