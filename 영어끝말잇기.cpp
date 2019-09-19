#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
   
   	for (int i = 1; i < words.size(); i++) {
		int num = i%n + 1 ;
   		int turn = i/n + 1;

   		for (int j = 0; j < i; j++) {
   			if (words[i] == words[j]) {
   				answer = {num, turn};
   				return answer;
   			}
   		}

   		int size = words[i-1].size();
   		
   		if (words[i-1][size-1] != words[i][0]) {
   			answer = {num, turn};
   			return answer;

   		} 

   	}

   	answer = {0,0};

    return answer;
}