#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(string word) {
    int answer = 0;
    int weight[] = {781, 156, 31, 6, 1};
    map<char, int> m = {{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}};
    
    for (int i = 0; i < word.length(); i++) {
        // (해당 알파벳의 인덱스 * 그 자리의 가중치) + 1(자기 자신)
        answer += m[word[i]] * weight[i] + 1;
    }
    
    return answer;
}