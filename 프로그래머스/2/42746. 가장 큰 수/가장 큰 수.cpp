#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs;
    for(auto& n : numbers) {
        strs.push_back(to_string(n));
    }
    
    sort(strs.begin(), strs.end(), [](string a, string b){
        int n1 = stoi(a + b);
        int n2 = stoi(b + a);
        return n1 > n2;
    });
    
    if(strs[0] == "0") return "0";
    for(auto& str : strs) {
        answer += str;
    }
    return answer;
}