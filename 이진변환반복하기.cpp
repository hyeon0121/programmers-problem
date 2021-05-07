#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int zero = 0;
    int num;
    int cnt = 0;
    
    while(s.size() > 1) {
        cnt++;
        
        int z = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') z++;
        }
        
        zero += z;
        int num = s.size()-z;
        s = "";
        
        while(num > 1) {
            s = to_string(num%2) + s;
            num /= 2;
        }
        
        s += "1";
    }
    
    return {cnt,zero};
}