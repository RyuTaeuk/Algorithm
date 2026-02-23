#include <string>
#include <vector>
#include <bitset>

using namespace std;

unsigned long solution(int n) {
    unsigned long answer;
    // n을 2진수로 만들어 놓기
    bitset<20> n_to_b(n);
    // 1 개수 구하기
    int cnt = n_to_b.count();
    // 1씩 더하기
    // 1의 갯수 같으면 스탑
    while(true) {
        bitset<20> next_big(++n);
        if(next_big.count() == cnt) {
            answer = next_big.to_ulong();
            break;
        }
    }
        
    return answer;
}