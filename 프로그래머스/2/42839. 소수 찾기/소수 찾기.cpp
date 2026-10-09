#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

// dfs로 조합하기
// isPrime 만들어서 확인
bool isPrime(int num) {
    if(num < 2) return false;
    for(int i=2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

set<int> s;
bool visited[8] = {false, };
void dfs(string numbers, int value, int cnt) {
    if(value > 0) s.insert(value);
    
    if(cnt == numbers.size()) return;
    
    for(int i = 0; i<numbers.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(numbers, value * 10 + (numbers[i] - '0'), cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    dfs(numbers, 0, 0);
    for(auto& num : s) {
        if(isPrime(num)) answer++;
    }
    return answer;
}