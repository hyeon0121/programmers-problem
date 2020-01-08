#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    stack<char> stk;
    int size = number.length() - k;
   	int cnt = 0;

    for (int i = 0; i < number.length(); i++) {
    	char ch = number[i];

    	// k번 숫자를 뺏을 경우 그 후에 나오는 숫자들은 그냥 넣음
    	while (!stk.empty() && cnt < k) {
    		char top = stk.top();

    		if(top >= ch) {
    			break;
    		}

			stk.pop();
    		cnt++;
    	}

    	stk.push(ch);
    }

    // 같은 수가 연달아 나왔을 경우 스택에 남아있는 숫자는 내림차순 이므로 뒤의 숫자부터 빼냄
    while (stk.size() != size) {
    	stk.pop();
    }
    
    while (!stk.empty()) {
    	char top = stk.top();
    	answer = top + answer;
    	stk.pop();
    }

    return answer;
}

int main(void) {
	string number = "4177252841";
	int k = 4;

	cout << solution(number, k) << endl;	
}