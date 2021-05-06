#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

string solution(string str) {
    string res = "error";
    string answer;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            int si = 0;
            int ni = i;

            while(si < i && ni < str.size()) {
                answer += str[si];
                if (str[si+1] >= 'a' && str[si+1] <= 'z') {
                    answer += str[si+1];
                    si++;
                }

                if (str[ni] == '1') {
                    if (ni+1 < str.size() && str[ni+1] == '0') {
                        answer += "10";
                        ni++;
                    }
                } else {
                    answer += str[ni];
                }

                si++;
                ni++;
            }
    
            if (si == i && ni == str.size()) res = answer;
            break;
        }
    }

    return res;

}
int main() {
    cout << solution("1");
}