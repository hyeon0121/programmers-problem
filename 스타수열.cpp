#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    vector<int> arr(a.size()+1, 0);

    for (int i = 0; i < a.size(); i++) {
        arr[a[i]]++;
    }
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) continue;
        if (arr[i] <= answer) continue;
        
        int cnt = 0;
        for (int j = 0; j < a.size()-1; j++) {
            if (a[j] != i && a[j + 1] != i) continue;
            if (a[j] == a[j + 1]) continue;
            
            cnt++;
            j++;
            
        }
        
        answer = max(answer,cnt);
    }
    
    return answer*2;
}