#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left; i<=right; i++) {
        // i / n 으로 몫을 구한다.
        // (i / n) + 1 이 최소값
        // 최소값보다 작으면 최소값을 넣는다
        // 아니면 i % n + 1 을 넣는다
        long long min_val = i / n + 1;
        long long num = i % n + 1;
        if(num < min_val)
            answer.push_back(min_val);
        else
            answer.push_back(num);
    }
    return answer;
}