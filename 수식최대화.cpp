#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<char> exp;
vector<long long> num;
vector<char> location;
vector<char> v;
bool visited[3];
long long answer;
void dfs(int cnt) {
  if (cnt == exp.size()) {    
    vector<long long> t_num = num;
    vector<char> t_location = location;

    for (int i = 0; i < v.size(); ++i) {
      //cout << v[i] << " ";
      for (int j = 0; j < t_location.size(); ++j) {
        cout << j << " " << t_location.size() << " ";
          if (t_location[j] == v[i]) {
            if(t_location[j] == '+') 
              t_num[j] = t_num[j] + t_num[j + 1];
            else if(t_location[j] == '-')
              t_num[j] = t_num[j] - t_num[j + 1];
            else if(t_location[j] == '*')
              t_num[j] = t_num[j] * t_num[j + 1];


            t_num.erase(t_num.begin() + j + 1);
            t_location.erase(t_location.begin() + j);
            j--;

            //cout << t_num.size() << " " << t_location.size() << endl;
          }
        }
        cout << endl;

    }

    //cout << t_num[0] << endl;

    if (abs(t_num[0]) > answer) {
      answer = abs(t_num[0]);
    }

    return;
    
  }
  for (int i = 0; i < exp.size(); ++i) {
    if (find(v.begin(), v.end(),exp[i]) == v.end()) {
      v.push_back(exp[i]);
      dfs(cnt+1);
      v.pop_back();   
    }
    
  }

}
long long solution(string expression) {
    answer = 0;
    string n = "";
    for (int i = 0; i < expression.size(); ++i) {
      if (isdigit(expression[i])) {
        n += expression[i];
      } else {

        if (find(exp.begin(), exp.end(),expression[i]) == exp.end()) {
          exp.push_back(expression[i]);
        }
        location.push_back(expression[i]);
        num.push_back(stoi(n));
        n = "";
      }
    }

    num.push_back(stoi(n));

    dfs(0);

    return answer;
}