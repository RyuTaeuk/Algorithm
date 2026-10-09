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
    if(cnt == numbers.size()) {
        if(value > 0) s.insert(value);
        return;
    }
    
    for(int i = 0; i<numbers.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(numbers, value * 10 + (numbers[i] - '0'), cnt + 1);
            dfs(numbers, value, cnt + 1); // 확인했으나 선택하지 않은 경우?
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