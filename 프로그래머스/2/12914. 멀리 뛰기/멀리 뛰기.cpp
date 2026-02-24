#include <string>
#include <vector>

#define DIV 1234567

using namespace std;

long long solution(int n) {
    vector<long long> dp(n+1);
    // 0칸일때 아무것도 안하는 가짓수 1
    dp[0] = 1;
    // 1칸일 때 1칸 뛰는 가짓수 1
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        // i번째 가짓수 = i-1번째 가짓수 + i-2번째 가짓수
        dp[i] = (dp[i-1] + dp[i-2]) % DIV;
    }
    
    long long answer = dp[n];
    return answer;
}