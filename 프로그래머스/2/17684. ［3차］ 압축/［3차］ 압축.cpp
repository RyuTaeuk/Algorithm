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
        while(j < msg.size() && dict.find(str + msg[j]) != dict.end()) {
            str += msg[j++];
        }
        answer.push_back(dict[str]);
        if (j< msg.size()) dict[str + msg[j]] = idx++;
        i += str.size();
        cout << str << '\n';
    }
    return answer;
}