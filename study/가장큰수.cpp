#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (const string &a , const string &b) {
    if (a+b > b+a) {
        return true;
    }
    
    return false;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    
    int check = 0;
    
    for (int i = 0; i < numbers.size(); i++) {
        int n = numbers[i];
        tmp.push_back(to_string(n));
        check += n;
    }
    
    if (check == 0) {
        return "0";
    }
    
    sort(tmp.begin(), tmp.end(), cmp);
    
    for (int i = 0; i < tmp.size(); i++) {
        answer += tmp[i];
    }
    
    return answer;
}