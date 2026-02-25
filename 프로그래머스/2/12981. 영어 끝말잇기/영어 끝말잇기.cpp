#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    unordered_map<string, int> m;
    
    for(int i=0; i<words.size(); i++) {
        if(m[words[i]] != 0 
           || (i>0 && words[i-1][words[i-1].size()-1] != words[i][0])) {
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            return answer;
        }
        m[words[i]]++;
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}