##include <iostream>

using namespace std;

int solution(int n, int a, int b){
    int answer = 0;
    int round = 0;
    
    while (a != b) {
        if (a % 2 == 0) {
            a /= 2;
        } else {
            a /= 2;
            a++;
        }

        if (b % 2 == 0) {
            b /= 2;
        } else {
            b /= 2;
            b++;
        }
        
        round++;
    }
    
    cout << a << b << endl;
    answer = round;
    return answer;
}