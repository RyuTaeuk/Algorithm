#include <iostream>

using namespace std;

int solution(int n) {
    // 1. 가장 오른쪽 1의 위치 찾기
    int c = n & -n;
    
    // 2. 1의 패턴에 1을 더해서 자리 올림 발생시키기
    int r = n + c;
    
    // 3. 바뀐 부분의 1들을 맨 오른쪽으로 밀어서 붙이기
    int answer = r | (((n ^ r) >> 2) / c);
    
    return answer;
}