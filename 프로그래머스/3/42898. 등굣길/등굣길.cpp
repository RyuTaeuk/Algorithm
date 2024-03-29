#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[101][101] = {0,};
    
    for(auto p : puddles){
        dp[p[1]][p[0]] = -1;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i == 1 && j == 1) dp[i][j] = 1;
            else if (dp[i][j] != -1) {
                int sum = 0;
                sum += (dp[i-1][j] == -1 ? 0 : dp[i-1][j]);
                sum += (dp[i][j-1] == -1 ? 0 : dp[i][j-1]);
                dp[i][j] = sum % 1000000007;
            }
        }
    }
    
    answer = dp[n][m];
    return answer;
}