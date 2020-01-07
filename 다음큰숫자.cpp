#include <string>
#include <vector>

using namespace std;

int countOne(int n) { 
    int total = 0;
    int num = n;
    
    while (num > 1) {
        if (num % 2 == 1) {
            total++;
        }
        
        num = num / 2;
    }
    
    return total;  
    
}

int solution(int n) {
    int answer = 0;

    int cnt = countOne(n);
    
    while (true) {
        n++;
        if (countOne(n) == cnt) {
            answer = n; 
            break;
        }
       
    }
    
    return answer;
}