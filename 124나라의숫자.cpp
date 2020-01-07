#include <string>
#include <vector>

using namespace std;

string solution(int n) {
  string answer = "";
      
  while (n > 0) {
    if (n % 3 == 0) {
      answer.insert(0, "4");
      n = n / 3 - 1;
              
    } else {
      int tmp = n % 3;
      answer.insert(0, to_string(tmp)); 
      n = n / 3;
    } 
  }
     
  return answer;
}