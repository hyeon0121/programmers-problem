#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    int n = gems.size();
    
    set<string> s;
    unordered_map<string,int> m;
    
    for (int i = 0; i < n; i++) {
        s.insert(gems[i]);
    }
    
    int l = 0;
    int r = 0;
    
    for (int i = 0; i < n; i++) {
        m[gems[i]]++;
        if (m.size() == s.size()) {
            r = i;
            break;
        }
    }
    
    answer[0] = l+1;
    answer[1] = r+1;
    int res = r-l;
        
    while(1) {
        string gem = gems[l];
        m[gem]--;
        l++;
        
        if (m[gem] == 0) {
            r++;
            while(r<n) {
                m[gems[r]]++;
                if (gems[r] == gem) {
                    break;
                }
                r++;
            }
        }
                
        if (l == n || r == n) break;
        
        if (res > r-l) {
            //cout << res << ',' << l << ',' << r << endl;
            answer[0] = l+1;
            answer[1] = r+1;
            res = r-l;
        }
    }
    return answer;
}