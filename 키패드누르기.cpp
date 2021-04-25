#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int dist[] = {0,1,2,1,2,3,2,3,4,3,4};
    
    int left = 10;
    int right = 12;
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if (num == 1 || num == 4 || num == 7) {
            answer += "L";
            left = num;
        } else if (num > 0 && num%3 ==0) {
            answer += "R";
            right = num;
        } else {
            if (num == 0) num = 11;
            
            int ld = dist[abs(num-left)];
            int rd = dist[abs(num-right)];
            
            if (ld < rd) {
                answer += "L";
                left = num;
            } else if (rd < ld) {
                answer += "R";
                right = num;
            } else {
                if (hand == "left") {
                    answer += "L";
                    left = num;
                } else {
                    answer += "R";
                    right = num;
                }
            }
        }
        
        //cout << left << ',' << right << endl;
        
    }
    return answer;
}