#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int Backtracking(int hp, vector<vector<int>> &dungeons, vector<bool> &visited, int cnt) {
    int result = cnt;
    
    for(int i=0; i<dungeons.size(); i++) {
        if(visited[i] || hp < dungeons[i][0])
            continue;
        
        // i번째 던전을 방문
        // i번째 던전을 방문한 경우 중 max값들 끼리 비교하기
        visited[i] = true;
        result = max(result,
                     Backtracking(hp-dungeons[i][1], dungeons, visited, cnt+1));
        //후진
        visited[i] = false;
    }
    
    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    int answer = Backtracking(k, dungeons, visited, 0);
    return answer;
    
    
}