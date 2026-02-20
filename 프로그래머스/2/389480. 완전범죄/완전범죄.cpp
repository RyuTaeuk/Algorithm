#include <string>
#include <vector>
#include <algorithm>

#define INF 1987654321

using namespace std;

//DP인듯

int solution(vector<vector<int>> info, int n, int m) {
    int items = info.size();
    // m개 이상이면 끝 -> m개 '미만' 이어야함
    vector<vector<int>> dp(items+1, vector<int>(m, INF));
    // 고려할 물건이 아직 없을 때, b의 흔적도 0이고, a의 흔적도 0임
    dp[0][0] = 0;
    
    for(int i=1; i<=items; i++) {
        for(int j=0; j<m; j++) {
            // i번째 물건을 가져가는 경우
            // b의 흔적이 j일때
            // case 1. A가 가져간다 -> A의 흔적을 dp에 반영
            // info는 0부터 시작한다. 주의.
            if(dp[i-1][j] != INF)
                dp[i][j] = min(dp[i][j], dp[i-1][j] + info[i-1][0]);
            // case 2. B가 가져간다 -> B가 j-info[i][1] 일 때 B가 가져가야함
            if(j >= info[i-1][1] && dp[i-1][j-info[i-1][1]] != INF)
                dp[i][j] = min(dp[i][j], dp[i-1][j-info[i-1][1]]);
        }
    }
    
    int answer = INF;
    for(int i=0; i<m; i++)
        answer = min(answer, dp[items][i]);
    return (answer < n) ? answer : -1;
}