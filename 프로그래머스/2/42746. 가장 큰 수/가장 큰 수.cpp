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
    
    if(strs[0] == "0") return "0"; // 예외 처리: 가장 큰 수가 0일때 + 0이 여러개면 "00" 이 아닌 "0" 이 답 (0 또는 양의정수이므로 "0")
    for(auto& str : strs) {
        answer += str;
    }
    return answer;
}