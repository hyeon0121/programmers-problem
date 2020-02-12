#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int bar = 0;
    stack<char> s;

    for (int i = 0; i < arrangement.size(); i++) {
        if (arrangement[i] == ')') {
            if (s.top() == '(') {
                bar--;
                answer+=bar;
                s.push(arrangement[i]);
            } else {
                answer++;
                bar--;
                s.push(arrangement[i]);
            }
        } else {
            bar++;
            s.push(arrangement[i]);
        }
    }
    return answer;
}