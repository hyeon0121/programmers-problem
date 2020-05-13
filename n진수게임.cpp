#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    char c[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; 
    string s = "0";
    string answer = "";
    
    for (int i = 1; i < t*m; i++) {
        int num = i;
        string tmp = "";
        while(1) {
            if (num == 0) break;
            tmp = c[num%n] + tmp;
            num /= n;
        } 
        
        s += tmp;
    }
    
     for (int i = 0; i < t*m; i++) {
         if ((i+1) % p == 0) {
            answer += s[i];
            p += m;
         }
     }
    
    return answer;
}