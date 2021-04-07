#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;
bool is_right(string str) { 
    if (str.size() == 0) return true; 

    int cnt = 0;
    if (str[0] == '(') cnt++;
    else return false;

    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == '(') cnt++;
        else cnt--;

        if (cnt < 0) {
            return false;
        }

    }

    return true;

}
string dfs(string p) {
    if (p.size() == 0) return p;
    
    string u;
    string v;

    int cnt;
    if (p[0] == '(') {
        cnt = 1;
    } else {
        cnt = -1;
    }
    for (int i = 1; i < p.size(); i++) {
        if (p[i] == '(') cnt++;
        else cnt--;

        if (cnt == 0) {
            u = p.substr(0,i+1);
            v = p.substr(i+1);
            break;
            
        }
    }

    //cout << u << " " << v << endl;
    
    if (is_right(u)) {
        return u + dfs(v);
    } else {
        string s = "(" + dfs(v) + ")";
        string tmp = "";

        if (u.size() > 2) {
            for (int j = 1; j < u.size()-1; j++) {
                if (u[j] == '(') {
                    tmp += ')';
                } else {
                    tmp += '(';
                }
            }
        }
        return s+tmp;
    }

}
string solution(string p) {
    string answer = dfs(p);
        
    return answer;
}