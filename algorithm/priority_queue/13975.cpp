#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, m;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int k; cin >> k;
        while (k--) {
            int tmp; cin >> tmp;
            pq.push(tmp);
        }
        long long cnt = 0;
        while (pq.size() > 1) {
            long long num1 = pq.top(); pq.pop();
            long long num2 = pq.top(); pq.pop();

            cnt += num1 + num2;
            pq.push(num1 + num2);
        }
        cout << cnt << '\n';
    }
    return 0;
}

