#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    string up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lo = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            int idx = s[i] - 'A' + n;
            s[i] = up[idx%26];
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            int idx = s[i] - 'a' + n;
            s[i] = lo[idx%26];
        }
    }

    return s;
}