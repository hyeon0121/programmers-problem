#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> arr) {
    int answer = 987654321;
    map<int,int> m;

    for (int i = 0; i < arr.size(); ++i) {
        if (m[arr[i]] != 0) {
            answer = min(answer, (i+1)-m[arr[i]]);
        }

        m[arr[i]] = i+1;

    }

    if (answer == 987654321) return -1;
    return answer;

}
int main() {
    vector<int> v = {2, 1, 3, 1, 4, 2, 1, 3};
    cout << solution(v);
}