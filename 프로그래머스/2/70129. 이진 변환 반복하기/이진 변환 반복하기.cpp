#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int c;
    while(s != "1") {
        answer[0]++; //이진 변환 횟수
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '1')
                c++;
            else
                answer[1]++; //0 제거횟수
        }
        string new_s = "";
        while(c != 0) {
            new_s = to_string(c%2) + new_s;
            c /= 2;
        }
        s = new_s;
    }

    
    
    return answer;
}