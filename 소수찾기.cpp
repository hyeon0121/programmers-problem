#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
string s = "";
int answer = 0;
bool visited[8];
bool chk[1000000];
bool isPrime(int num) {
    if (num < 2) return false;
    
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    
    return true;
}
void dfs(int cnt, int n, string numbers) {
    if (cnt == n) {
        int num = stoi(s);
        if (isPrime(num) && !chk[num]) {
            chk[num] = true;
            answer++;
        }
        return;
    }
    
    for (int i = 0; i < numbers.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        s += numbers[i];
        dfs(cnt+1, n, numbers);
        s.pop_back();
        visited[i] = false;
    }
} 
int solution(string numbers) {
    for (int i = 1; i <= numbers.size(); i++) {
         dfs(0, i, numbers);
    }
   
    return answer;
}