#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int solution(string str1, string str2) {
    double answer = 65536;
   
    set<string> s;
    map<string,int> m1;
    map<string,int> m2;
    
    for (int i = 0; i < str1.size()-1; i++) {
        if (isalpha(str1[i]) && isalpha(str1[i+1])) {
            string s1,s2;
            s1 += toupper(str1[i]);
            s2 += toupper(str1[i+1]);
            m1[s1+s2]++;
            s.insert(s1+s2);
        }
    }
    
    for (int i = 0; i < str2.size()-1; i++) {
        if (isalpha(str2[i]) && isalpha(str2[i+1])) {
            string s1,s2;
            s1 += toupper(str2[i]);
            s2 += toupper(str2[i+1]);
            m2[s1+s2]++;
            s.insert(s1+s2);
        }
    }
    
    map<string,int> m, cmp;
    if (m1.size() > m2.size()) {
        m = m1;
        cmp = m2;
    } else {
        m = m2;
        cmp = m1;
    }
    
    int mn = 0;
    int mx = 0;
    
    for (auto i = s.begin(); i != s.end(); i++) {
        int s1 = m1[*i];
        int s2 = m2[*i];
        
        if (s1 > 0 && s2 > 0) {
            mn += min(s1,s2);
        } 
        
        mx += max(s1,s2);
        
        
    }
    
    if (mn == 0 && mx == 0) {
        return answer;
    } else {
        
        double d = (double)mn/(double)mx;
        
        return (int)(answer * d);
    }
    
    return answer;
}