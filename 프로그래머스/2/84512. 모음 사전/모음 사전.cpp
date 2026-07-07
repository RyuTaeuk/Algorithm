#include <string>
#include <vector>
#include <iostream>

using namespace std;

int count = 0;
char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
bool found = false;
void DFS (string word, string curr_state) {
    if(word == curr_state) {
        found = true;
        return;
    }
    count++;
    if(curr_state.length() == 5) {
        return;
    }
    //탐색
    for(auto &c : vowels) {
        curr_state = curr_state + c;
        DFS(word, curr_state);
        if(found) return;
        //curr_state에서 하나 지우기는 어캐하지
        curr_state.pop_back();
    }
    
    
}

int solution(string word) {
    DFS(word, "");
    int answer = count;

    return answer;
}