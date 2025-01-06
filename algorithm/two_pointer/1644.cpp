#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int n, m;
vector<int> valid_nums;
int arr[4000001] = {0, };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    for (int i = 2; i <= n; i++) arr[i] = i;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (arr[i] == 0) continue;
        for (int j = 2 * i; j <= n; j += i) arr[j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] != 0) valid_nums.push_back(i);
    }

    int en = 0;
    int cnt = 0;
    int sum = valid_nums[0];

    for (int st = 0; st < valid_nums.size(); st++) {
        while (en < valid_nums.size() && sum < n) {
            en++;
            if (en != valid_nums.size()) sum += valid_nums[en];
        }
        if (sum == n) cnt++;
        sum -= valid_nums[st];
    }

    cout << cnt << '\n';

    return 0;
}

