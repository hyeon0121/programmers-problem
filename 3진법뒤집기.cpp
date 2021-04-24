#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

int solution(int n) {
    int answer = 0;
    
    int num = n;
    string s = "";
    while(num > 0) {
        s = to_string(num%3)+s;
        num /= 3;
    }
    
    for (int i = 0; i < s.size(); i++) {
        answer += (s[i] - '0') * pow(3,i);
    }
    //cout << s;
    return answer;
}