#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int p;
int main() {
    cin >> p;

    for (int i = p+1; i <= 12345; ++i) {
        string s = to_string(i);
        sort(s.begin(), s.end());

        bool flag = false;
        for (int j = 1; j < s.size(); ++j) {
            if (s[j-1] == s[j]) {
                flag = true;
                break;
            }
        }

        if (!flag) return i;
    }
}