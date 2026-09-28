#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    int idx = 1;
    for(char c = 'A'; c <= 'Z'; c++) {
        string str(1, c);
        dict[str] = idx++;
    }
    int i=0;
    while(i < msg.size()) {
        int j = i;
        string str = "";
        string next_str = "";
        while(j < msg.size()) {
            next_str += msg[j];
            if(dict.find(next_str) == dict.end()) break;
            j++;
            str = next_str;
        }
        i += str.size();
        cout << str << '\n';
        
        answer.push_back(dict[str]);
        if (j< msg.size()) dict[next_str] = idx++;
    }
    return answer;
}