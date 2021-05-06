#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int dp[1000001];
int solution(vector<int> arr) {
    dp[0] = 0;
    int lm = 0;
    int rm = 0;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] >= arr[dp[i-1]]) {
            dp[i] = i;
            rm = max(rm,i-dp[i-1]);
        } else {
            lm = max(lm,i-dp[i-1]);
            dp[i] = dp[i-1];
        }
    }

    return max(lm,rm);

}
int main() {
    vector<int> v {8,4,7,8,10,2,9,7,8,12};
    cout << solution(v);
}