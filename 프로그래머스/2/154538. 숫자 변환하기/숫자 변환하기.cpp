#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 얘 dp였던거같은데
#define MAX_NUM 100000000
int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> dp(1000001, MAX_NUM);
    dp[x] = 0;
    for(int i=x+1; i<=y; i++) {
        if(i-n >= 0) dp[i] = min(dp[i], dp[i-n] + 1);
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    if(dp[y] >= MAX_NUM) return -1;
    answer = dp[y];
    return answer;
}