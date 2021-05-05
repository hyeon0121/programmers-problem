#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int dp[100001];
int main() {
    cin >> n;

    dp[1] = 1;
    int b = 1;
    int num = 3;
    int index = 0;

    for (int i = 2; i <= n; ++i) {
        if (pow(2,b) == i) {
            num = pow(3,b);
            dp[i] = num;
            b++;
            index = 0;
        }

        dp[i] = num + dp[index];
        index++;

    }

    cout << dp[n];
}